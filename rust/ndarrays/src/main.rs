fn main() {
    let val = 3;
    let length = 32;
    let array1d = [val; length];
    // let array2d = [array1d; length]; // or [[3; 32]; 32];
    // let array3d = [array2d; length]; // or [[[3; 32]; 32]; 32];
    println!("{:?}", array1d);
}
