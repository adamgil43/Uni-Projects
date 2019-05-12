package com.example.adam.gilmour5_300cem;

/*
Places contains Description, image_url, latitude, longitude, title.
 */
public class Places {
    private String description, image_url, latitude, longitude, title;

    public Places(String description, String image_url, String latitude, String longitude, String title) {
        this.description = description;
        this.image_url = image_url;
        this.latitude = latitude;
        this.longitude = longitude;
        this.title = title;
    }

    public Places () {};

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getImage_url() {
        return image_url;
    }

    public void setImage_url(String image_url) {
        this.image_url = image_url;
    }

    public String getLatitude() {
        return latitude;
    }

    public void setLatitude(String latitude) {
        this.latitude = latitude;
    }

    public String getLongitude() {
        return longitude;
    }

    public void setLongitude(String longitude) {
        this.longitude = longitude;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }
}
