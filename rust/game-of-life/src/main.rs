mod cell;
mod grid;

use std::collections::VecDeque;
use cell::Cell;
const NUM_CELLS: usize = 5;


pub fn handle_neighbours(x: usize,
                         y: usize,
                         pneighbours: &mut i32,
                         babyq: &mut VecDeque<Cell>,
                         grid: &mut [[cell::Cell; NUM_CELLS]; NUM_CELLS]) {

    for row in x - 1..x + 1 {
        // is it only till x+1?
        for col in y - 1..y + 1 {
            match grid[row][col] {
                Cell::Alive { x, y, neighbours } => {
                    // if self then skip
                    if row == x && col == y {
                        continue;
                    } else {
                        *pneighbours += 1;
                    }
                }
                Cell::Baby { x, y, neighbours } => {}
                Cell::Empty {} => {}
            }
        }
    }
}

fn main() {
    let mut cellq: VecDeque<Cell> = VecDeque::with_capacity(NUM_CELLS);
    cellq.push_back(Cell::Alive {
                        x: 3,
                        y: 4,
                        neighbours: 0,
                    });

    let mut babyq: VecDeque<Cell> = VecDeque::with_capacity(NUM_CELLS);

    let mut grid = [[Cell::Empty; NUM_CELLS]; NUM_CELLS]; // 2D array NUM_CELLS x NUM_CELLS

    while let Some(c) = cellq.pop_front() {
        match c {
            Cell::Alive {
                x,
                y,
                mut neighbours,
            } => {
                handle_neighbours(x, y, &mut neighbours, &mut babyq, &mut grid);
            }
            Cell::Baby { x, y, neighbours } => {
                panic!("Cell Queue must not have anything other than cells")
            }
            Cell::Empty {} => {}
        }
    }
}

