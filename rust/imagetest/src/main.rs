extern crate image;

use std::fs::File;
use std::path::Path;

use image::{
    GenericImage,
    ImageBuffer
};


fn main() {
    // Use the open function to load an image from a Path.
    // ```open``` returns a dynamic image.
    let img = image::open(&Path::new(r"C:\Users\dimta\Downloads\e4aa5ef665cb327c6be2544cc6e43e11.png")).unwrap();

    // The dimensions method returns the images width and height
    println!("dimensions {:?}", img.dimensions());

    img += 1;

    // The color method returns the image's ColorType
    println!("{:?}", img.color());
    println!("Hello, world!");
}
