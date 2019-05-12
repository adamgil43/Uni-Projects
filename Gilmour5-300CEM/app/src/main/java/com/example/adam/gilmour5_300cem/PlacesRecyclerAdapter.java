package com.example.adam.gilmour5_300cem;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import java.net.URL;
import java.util.ArrayList;
import java.util.List;

class PlacesRecyclerAdapter extends RecyclerView.Adapter<PlacesRecyclerAdapter.ViewHolder> {
    private List<Places> placesList;
    public Context mContext;

    public PlacesRecyclerAdapter(List<Places> placesList, Context mContext) {
        this.placesList = placesList;
        this.mContext = mContext;
    }

    @NonNull
    @Override
    public PlacesRecyclerAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.place_views, parent, false);
        return new ViewHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull PlacesRecyclerAdapter.ViewHolder viewHolder, final int i) {
        viewHolder.setIsRecyclable(false);
        String title_data = placesList.get(i).getTitle();
        String description_data = placesList.get(i).getDescription();
        String image_url = placesList.get(i).getImage_url();
        String longitude_data = placesList.get(i).getLongitude();
        String latitude_data = placesList.get(i).getLatitude();

        viewHolder.setTvDescription(description_data);
        viewHolder.setTvTitle(title_data);
        viewHolder.setImage(image_url);

        final String mapString = "https://www.google.com/maps/dir/?api=1&origin=&destination= " + latitude_data +", " + longitude_data + "&travelmode=driving";

        viewHolder.btnDirections.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(Intent.ACTION_VIEW);
                i.setData(Uri.parse(mapString));
                mContext.startActivity(i);
            }
        });
    }

    @Override
    public int getItemCount() {
        return placesList.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder{

        ImageView ivPlaces;
        TextView tvTitle, tvDescription;
        Button btnDirections;
        View mView;


        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            mView = itemView;

            btnDirections = itemView.findViewById(R.id.getDirections);

        }

        public void setTvDescription(String description){
            tvDescription = mView.findViewById(R.id.tvDescription);
            tvDescription.setText(description);
        }

        public void setTvTitle(String title){
            tvTitle = mView.findViewById(R.id.tvTitle);
            tvTitle.setText(title);
        }

        public void setImage(String downloadUri){
            ivPlaces = mView.findViewById(R.id.ivPlacess);

            Picasso.get().load(Uri.parse(downloadUri)).into(ivPlaces);

        }
    }


}
