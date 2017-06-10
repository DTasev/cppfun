const NEIGHBOURS_TO_LIVE: u32  = 2;
const NEIGHBOURS_TO_PROCREATE: u32  = 3;
const NEIGHBOURS_TO_DIE: u32  = 4;

#[derive(Debug)]
pub enum Cell{
    Alive { x: i32, y: i32, neighbours: i32 },
    Baby { x: i32, y: i32, neighbours: i32 },
    Empty
}
