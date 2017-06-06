use std::thread;

fn main() {
    let x = 1;
    thread::spawn(|| {
        println!("x is {}", x);
    });
    println!("x is here {}", x);
}