from itertools import permutations
import math
import random
from time import time
import numpy as np
from math import inf as oo
import matplotlib.pyplot as plt
from tqdm import tqdm


def generate_graph(size):
    """"Generate Graph of size"""
    graph = []
    for i in range(size):
        # point1 = random.randint(0, size * 10)
        point1 = random.randint(0, 100)
        point2 = random.randint(0, 100)
        # point2 = random.randint(0, size * 10)
        node = [i, point1, point2]
        graph.append(node.copy())
    return graph


def load_graph_from_file(filepath):
    """Load graph from TSPLib"""
    file = open(filepath, 'r')
    line_count = 0
    graph = []
    for line in file.readlines():
        point = []
        line_count += 1
        if line_count > 6:
            for section in line.split(' '):
                if section == 'EOF\n':
                    break
                point.append(int(section))
            graph.append(point)
    return graph


class TSP(object):
    def __init__(self, graph, start_temperature, cooling_rate, minimum_temperature, max_iterations):
        self.graph = graph
        self.graph_size = len(graph)
        self.temperature = math.sqrt(self.graph_size) if start_temperature == -1 else start_temperature
        self.temperature_original = self.temperature  # Used to save temperature for batch
        self.cooling_rate = 0.995 if cooling_rate == -1 else cooling_rate
        self.minimum_temperature = 1e-8 if minimum_temperature == -1 else minimum_temperature
        self.max_iterations = 100000 if max_iterations == -1 else max_iterations
        self.iteration_count = 1

        self.node_names = [i for i in range(self.graph_size)]
        self.best_solution = None
        self.best_cost = oo
        self.cost_list = []

        self.current_solution = []
        self.current_cost = oo

    def exhaustive_solution(self):
        """Find the perfect solution for a graph"""
        n = len(self.graph)
        best_cost = oo
        best_path = []
        for path in permutations(self.node_names[:len(self.node_names) - 1]):
            path = list(path)
            path.append(path[0])
            c = self.solution_cost(path)
            if c < best_cost:
                best_cost = c
                best_path = path
        return best_path, best_cost

    def greedy_best(self):
        best_solution = []
        best_score = oo
        for i in range(len(self.node_names)):
            res = self.greedy_solution(self.node_names[i])
            if res[1] < best_score:
                best_solution = res[0]
                best_score = res[1]
        return best_solution, best_score

    def greedy_solution(self, current_node):
        """Greedy nearest neighbour solution for a given graph"""
        greedy_solution = []
        greedy_solution.append(current_node)

        not_visited_nodes = set(self.node_names)
        not_visited_nodes.remove(current_node)
        while not_visited_nodes:
            new_node = min(not_visited_nodes, key=lambda n: self.distance(current_node, n))
            not_visited_nodes.remove(new_node)
            greedy_solution.append(new_node)
            current_node = new_node
        greedy_solution.append(greedy_solution[0])
        return greedy_solution, self.solution_cost(greedy_solution)

    def distance(self, current_node, new_node):
        """Calculate the cost between 2 nodes"""
        x = [self.graph[current_node][1], self.graph[new_node][1]]
        y = [self.graph[current_node][2], self.graph[new_node][2]]
        distance = math.sqrt((x[0] - x[1]) ** 2 + (y[0] - y[1]) ** 2)
        return distance

    def solution_cost(self, solution):
        """Calculate teh cost of a solution"""
        solution_cost = 0
        for i in range(len(solution) - 1):
            solution_cost += self.distance(solution[i], solution[i + 1])
        return solution_cost

    def accept_probability(self, new_solution_cost):
        """Returns the probability for the new solution found to be accepted"""
        return math.exp(-abs(new_solution_cost - self.current_cost) / self.temperature)

    def accept_new_solution(self, new_solution):
        """Automatically accept a solution if it is better.
            Otherwise, only accept if the probability is greater than random number"""
        new_solution_cost = self.solution_cost(new_solution)
        if new_solution_cost < self.current_cost:
            self.current_cost = new_solution_cost
            self.current_solution = new_solution
            if new_solution_cost < self.best_cost:
                self.best_cost = new_solution_cost
                self.best_solution = new_solution
        else:
            if random.random() < self.accept_probability(new_solution_cost):
                self.current_cost = new_solution_cost
                self.current_solution = new_solution

    def anneal(self, start_solution):
        """Run the simulated annealing algorithm"""
        # greedy = self.greedy_solution()
        self.current_solution = start_solution[0]
        self.current_cost = start_solution[1]
        self.best_solution = self.current_solution.copy()
        self.best_cost = self.current_cost
        while self.temperature >= self.minimum_temperature and self.iteration_count < self.max_iterations:
            candidate = list(self.current_solution)
            pos_1, pos_2 = 0, 0
            while pos_1 == pos_2:
                pos_1 = random.randint(2, self.graph_size - 1)
                pos_2 = random.randint(0, self.graph_size - pos_1)
            candidate[pos_2: (pos_2 + pos_1)] = reversed(candidate[pos_2: (pos_2 + pos_1)])
            candidate.pop()
            candidate.append(candidate[0])
            self.accept_new_solution(candidate)
            self.temperature *= self.cooling_rate
            self.iteration_count += 1
            self.cost_list.append(self.current_cost)
        return self.best_solution, self.best_cost

    def anneal_repeat(self, start_solution, num_to_repeat):
        """Run the simulated annealing algorithm multiple times to find a better solution"""
        record = ([], oo)
        for i in range(num_to_repeat):
            self.iteration_count = 1
            self.temperature = self.temperature_original
            result = self.anneal(start_solution)
            if result[1] < record[1]:
                record = result
        return record


def time_exhaustive_solution():
    graph_used = []
    list_of_graphs = []

    exhaustive_nodes = []

    start_time = 0
    end_time = 0
    graph_start_size = 5
    graph_used = []
    exhaustive_costs = []
    exhaustive_time = []
    while end_time - start_time < 20:
        start_time = time()
        graph = generate_graph(graph_start_size)
        graph_used.append(graph)
        tsp = TSP(graph, -1, -1, -1, -1)
        res = tsp.exhaustive_solution()
        end_time = time()
        total_time = end_time - start_time
        exhaustive_nodes.append(graph_start_size)
        exhaustive_time.append(total_time)
        exhaustive_costs.append(res[1])
        graph_start_size += 1
        print('Time taken: ', total_time)
        if graph_start_size >= 10:
            list_of_graphs.append(graph_used)
            return exhaustive_nodes, exhaustive_costs, exhaustive_time, graph_used


def time_greedy_solution_random(graph_list):
    greedy_time = []
    greedy_cost = []
    for graph in graph_list:
        tsp = TSP(graph, -1, -1, -1, -1)
        start_time = time()
        res = tsp.greedy_solution(random.choice(tsp.node_names))
        end_time = time()
        total_time = end_time - start_time
        greedy_cost.append(res[1])
        greedy_time.append(total_time)
    return greedy_cost, greedy_time


def time_greedy_solution_best(graph_list):
    greedy_time = []
    greedy_cost = []
    for graph in graph_list:
        tsp = TSP(graph, -1, -1, -1, -1)
        start_time = time()
        res = tsp.greedy_best()
        end_time = time()
        total_time = end_time - start_time
        greedy_cost.append(res[1])
        greedy_time.append(total_time)
    return greedy_cost, greedy_time


def time_annealing_solution_random(graph_list):
    annealing_time = []
    annealing_cost = []

    for graph in graph_list:
        tsp = TSP(graph, -1, -1, -1, -1)
        start_time = time()
        res = tsp.anneal(tsp.greedy_solution(random.choice(tsp.node_names)))
        end_time = time()
        total_time = end_time - start_time
        annealing_cost.append(res[1])
        annealing_time.append(total_time)
    return annealing_cost, annealing_time


def time_annealing_solution_best(graph_list):
    annealing_time = []
    annealing_cost = []

    for graph in graph_list:
        tsp = TSP(graph, -1, -1, -1, -1)
        start_time = time()
        res = tsp.anneal(tsp.greedy_best())
        end_time = time()
        total_time = end_time - start_time
        annealing_cost.append(res[1])
        annealing_time.append(total_time)
    return annealing_cost, annealing_time


def testing_exhaustive():
    # Variables used for testing purposes

    graph_used = []
    list_of_graphs = []

    exhaustive_nodes = []
    exhaustive_cost_average = []
    exhaustive_time_average = []

    greedy_random_cost_average = []
    greedy_random_time_average = []

    greedy_best_cost_average = []
    greedy_best_time_average = []

    annealing_best_cost_average = []
    annealing_best_time_average = []

    annealing_random_cost_average = []
    annealing_random_time_average = []

    for i in range(15):
        res = time_exhaustive_solution()
        list_of_graphs.append(res[3])
        exhaustive_time_average.append(res[2])
        exhaustive_cost_average.append(res[1])
        exhaustive_nodes = res[0]

    exhaustive_cost_average = np.array(exhaustive_cost_average)
    exhaustive_cost_average = np.average(exhaustive_cost_average, axis=0)
    exhaustive_cost_average = exhaustive_cost_average.tolist()

    exhaustive_time_average = np.array(exhaustive_time_average)
    exhaustive_time_average = np.average(exhaustive_time_average, axis=0)
    exhaustive_time_average = exhaustive_time_average.tolist()

    for graph_list in list_of_graphs:
        res = time_greedy_solution_random(graph_list)
        greedy_random_cost_average.append(res[0])
        greedy_random_time_average.append(res[1])

    greedy_random_cost_average = np.array(greedy_random_cost_average)
    greedy_random_cost_average = np.average(greedy_random_cost_average, axis=0)
    greedy_random_cost_average = greedy_random_cost_average.tolist()

    greedy_random_time_average = np.array(greedy_random_time_average)
    greedy_random_time_average = np.average(greedy_random_time_average, axis=0)
    greedy_random_time_average = greedy_random_time_average.tolist()

    for graph_list in list_of_graphs:
        res = time_greedy_solution_best(graph_list)
        greedy_best_cost_average.append(res[0])
        greedy_best_time_average.append(res[1])

    greedy_best_cost_average = np.array(greedy_best_cost_average)
    greedy_best_cost_average = np.average(greedy_best_cost_average, axis=0)
    greedy_best_cost_average = greedy_best_cost_average.tolist()

    greedy_best_time_average = np.array(greedy_best_time_average)
    greedy_best_time_average = np.average(greedy_best_time_average, axis=0)
    greedy_best_time_average = greedy_best_time_average.tolist()

    for graph_list in list_of_graphs:
        res = time_annealing_solution_best(graph_list)
        annealing_best_cost_average.append(res[0])
        annealing_best_time_average.append(res[1])

    annealing_best_cost_average = np.array(annealing_best_cost_average)
    annealing_best_cost_average = np.average(annealing_best_cost_average, axis=0)
    annealing_best_cost_average = annealing_best_cost_average.tolist()

    annealing_best_time_average = np.array(annealing_best_time_average)
    annealing_best_time_average = np.average(annealing_best_time_average, axis=0)
    annealing_best_time_average = annealing_best_time_average.tolist()

    for graph_list in list_of_graphs:
        res = time_annealing_solution_random(graph_list)
        annealing_random_cost_average.append(res[0])
        annealing_random_time_average.append(res[1])

    annealing_random_cost_average = np.array(annealing_random_cost_average)
    annealing_random_cost_average = np.average(annealing_random_cost_average, axis=0)
    annealing_random_cost_average = annealing_random_cost_average.tolist()

    annealing_random_time_average = np.array(annealing_random_time_average)
    annealing_random_time_average = np.average(annealing_random_time_average, axis=0)
    annealing_random_time_average = annealing_random_time_average.tolist()

    return exhaustive_nodes, exhaustive_cost_average, exhaustive_time_average, greedy_random_cost_average, greedy_random_time_average, greedy_best_cost_average, greedy_best_time_average, annealing_best_cost_average, annealing_best_time_average, annealing_random_cost_average, annealing_random_time_average


def plot_exhaustive_run(exhaustive_res):
    exhaustive_nodes = exhaustive_res[0]
    exhaustive_cost_average = exhaustive_res[1]
    exhaustive_time_average = exhaustive_res[2]

    greedy_random_cost_average = exhaustive_res[3]
    greedy_random_time_average = exhaustive_res[4]

    greedy_best_cost_average = exhaustive_res[5]
    greedy_best_time_average = exhaustive_res[6]

    annealing_best_cost_average = exhaustive_res[7]
    annealing_best_time_average = exhaustive_res[8]

    annealing_random_cost_average = exhaustive_res[7]
    annealing_random_time_average = exhaustive_res[8]

    plt.plot(exhaustive_nodes, exhaustive_cost_average, 'bo-', label='Exhaustive')
    plt.plot(exhaustive_nodes, greedy_random_cost_average, 'ro-', label='Greedy Random')
    plt.plot(exhaustive_nodes, greedy_best_cost_average, 'ro--', label='Greedy Best')
    plt.plot(exhaustive_nodes, annealing_best_cost_average, 'go-', label='Simulated Annealing Best')
    plt.plot(exhaustive_nodes, annealing_random_cost_average, 'go--', label='Simulated Annealing Random')
    plt.xlabel('Number of Nodes')
    plt.ylabel('Route Cost')
    plt.legend(loc='upper left')
    plt.show()
    plt.plot(exhaustive_nodes, exhaustive_time_average, 'bo-', label='Exhaustive')
    plt.plot(exhaustive_nodes, greedy_random_time_average, 'ro-', label='Greedy Random')
    plt.plot(exhaustive_nodes, greedy_best_time_average, 'ro--', label='Greedy Best')
    plt.plot(exhaustive_nodes, annealing_best_time_average, 'go-', label='Simulated Annealing Best')
    plt.plot(exhaustive_nodes, annealing_random_time_average, 'go--', label='Simulated Annealing Random')
    plt.xlabel('Number of Nodes')
    plt.ylabel('Time in Seconds')
    plt.legend(loc='upper left')
    plt.show()


def testing_large():
    nodes = []
    graph_list = []
    greedy_cost_random = []
    greedy_time_random = []
    greedy_cost_best = []
    greedy_time_best = []
    anneal_cost_random = []
    anneal_time_random = []
    anneal_cost_best = []
    anneal_time_best = []
    for i in range(5, 500, 50):
        graph = generate_graph(i)
        graph_list.append(graph)
        nodes.append(i)
    print('Graphs done')

    greedy_random = time_greedy_solution_random(graph_list)
    print('Greedy random done')
    greedy_best = time_greedy_solution_best(graph_list)
    print('Greedy best done')
    anneal_random = time_annealing_solution_random(graph_list)
    print('Anneal random done')
    anneal_best = time_annealing_solution_best(graph_list)
    print('Anneal best done')

    for i in range(len(greedy_random[0])):
        print('Adding to lists', i)
        greedy_cost_random.append(greedy_random[0][i])
        greedy_time_random.append(greedy_random[1][i])
        greedy_cost_best.append(greedy_best[0][i])
        greedy_time_best.append(greedy_best[1][i])
        anneal_cost_random.append(anneal_random[0][i])
        anneal_time_random.append(anneal_random[1][i])
        anneal_cost_best.append(anneal_best[0][i])
        anneal_time_best.append(anneal_best[1][i])
    print('Lists done')

    return nodes, greedy_time_random, greedy_cost_random, greedy_time_best, greedy_cost_best, anneal_time_random, anneal_cost_best, anneal_time_best, anneal_cost_best


def plot_large_run(run):
    nodes = run[0]
    greedy_time_random = run[1]
    greedy_cost_random = run[2]
    greedy_time_best = run[3]
    greedy_cost_best = run[4]
    anneal_time_random = run[5]
    anneal_cost_random = run[6]
    anneal_time_best = run[7]
    anneal_cost_best = run[8]

    print(len(nodes))
    print(len(greedy_time_random))
    plt.plot(nodes, greedy_time_random, 'ro-', label='Greedy random')
    plt.plot(nodes, greedy_time_best, 'ro--', label='Greedy best')
    plt.plot(nodes, anneal_time_random, 'go-', label='Anneal random')
    plt.plot(nodes, anneal_time_best, 'go--', label='Anneal best')
    plt.xlabel('Number of Nodes')
    plt.ylabel('Time in Seconds')
    plt.legend(loc='upper left')
    plt.show()
    plt.plot(nodes, greedy_cost_random, 'ro-', label='Greedy random')
    plt.plot(nodes, greedy_cost_best, 'ro--', label='Greedy best')
    plt.plot(nodes, anneal_cost_random, 'go--', label='Anneal random')
    plt.plot(nodes, anneal_cost_best, 'go--', label='Anneal best')
    plt.xlabel('Number of Nodes')
    plt.ylabel('Route Cost')
    plt.legend(loc='upper left')
    plt.show()


if __name__ == '__main__':
    # g = generate_graph(15)
    # s = TSP(g, -1, -1, -1, oo)
    # print(s.exhaustive_solution())
    # print(s.anneal_repeat(10))
    # print(s.greedy_solution())
    ex = testing_exhaustive()
    plot_exhaustive_run(ex)
    large = testing_large()
    plot_large_run(large)

    # att48 = load_graph_from_file('att48.tsp')
    # print(att48)
    # att48_sol = TSP(att48, -1, -1, -1, oo)
    # print(att48_sol.greedy_best())
    # print(att48_sol.anneal(att48_sol.greedy_best()))
    # print(att48_sol.anneal_repeat(att48_sol.greedy_best(), 5))
    # print(att48_sol.greedy_solution(att48_sol.node_names[0]))
    # print(att48_sol.anneal(att48_sol.greedy_solution(att48_sol.node_names[0])))
