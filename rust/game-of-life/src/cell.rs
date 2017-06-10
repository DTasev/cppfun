const NEIGHBOURS_TO_LIVE: u32 = 2;
const NEIGHBOURS_TO_PROCREATE: u32 = 3;
const NEIGHBOURS_TO_DIE: u32 = 4;

#[derive(Debug, Copy, Clone)]
pub enum Cell {
    Alive { x: usize, y: usize, neighbours: i32 },
    Baby { x: usize, y: usize, neighbours: i32 },
    Empty,
}

