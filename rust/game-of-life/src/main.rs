mod cell;
mod grid;

use std::collections::VecDeque;
use cell::Cell;
const NUM_CELLS: usize = 5;


pub fn handle_neighbours(x: &i32, y: &i32, neighbours: &i32, mut babyq: &VecDeque<Cell>, mut deathq: &VecDeque<Cell>){
    for row in x-1..x+1{ // is it only till x+1?
        for col in y-1..y+1{
            // nope this doesnt work
        }
    }
}

fn main() {
    let mut cellq: VecDeque<Cell> = VecDeque::with_capacity(START_CELLS);
    cellq.push_back(Cell::Alive {x: 3, y: 4, neighbours: 0});

    let mut babyq: VecDeque<Cell> = VecDeque::with_capacity(START_CELLS);

    let grid = [[0; NUM_CELLS]; NUM_CELLS]; // 2D array NUM_CELLSxNUM_CELLS

    // while let Some(c) = cellq.pop_front() {
    //     match c{
    //         Cell::Alive{x, y, neighbours} => {
    //             handle_neighbours(&x, &y, &neighbours, &babyq, &deathq);
    //         },
    //         Cell::Baby{x, y, neighbours} => panic!("Cell Queue must not have anything other than cells"),
    //     }
    // }
}
