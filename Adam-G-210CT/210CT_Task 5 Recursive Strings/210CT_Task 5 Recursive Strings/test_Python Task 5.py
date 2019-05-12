import unittest
import ReverseString

class TestPythonTask5(unittest.TestCase):

    def test_rev(self):
        result = ReverseString.rev("Hello there everyone")
        result2 = ReverseString.reverseList(result)
        self.assertEqual(result2, "olleH ereht enoyreve")
    def test_rev2(self):
        result = ReverseString.rev("My name is Adam")
        result2 = ReverseString.reverseList(result)
        self.assertEqual(result2, "yM eman si madA")
    def test_rev3(self):
        result = ReverseString.rev("Day Time Year Month")
        result2 = ReverseString.reverseList(result)
        self.assertEqual(result2, "yaD emiT raeY htnoM")

        
if __name__ == '__main__':
    unittest.main()
