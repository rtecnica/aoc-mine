pub enum Direction {
    Left,
    Right,
}

pub struct Dial {
    pub position: u16,
    pub zero_position: u16,
}

pub fn rot_dial(dial: &mut Dial, dir: Direction, amount: u16) {
    match dir {
        Direction::Left => dial.position = (dial.position + (amount % 100)) % 100,
        Direction::Right => dial.position = ((dial.position + 100) - (amount % 100)) % 100,
    }
    if dial.position == 0 {
        dial.zero_position = dial.zero_position + 1;
    }
}
