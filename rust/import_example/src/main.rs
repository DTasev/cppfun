mod subpackage;
mod toplvlpackage;

fn main() {
    toplvlpackage::publiccc();
    subpackage::helper::fef();
    println!("Hello, world!");
}
