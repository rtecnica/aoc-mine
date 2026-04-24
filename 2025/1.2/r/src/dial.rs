pub enum Direction {
    Left,
    Right,
}

pub struct Dial {
    pub position: u32,
    pub zero_count: u32,
}

pub fn rot_dial(dial: &mut Dial, dir: Direction, amount: u32) {
    let pre_position = dial.position;
    let zero_cross;
    match dir {
        Direction::Right => {
            dial.position = (dial.position + (amount % 100)) % 100;
            zero_cross = pre_position > dial.position;
        }
        Direction::Left => {
            dial.position = ((dial.position + 100) - (amount % 100)) % 100;
            zero_cross = pre_position < dial.position;
        }
    }
    let dial_at_zero = dial.position == 0;
    dial.zero_count = dial.zero_count + (amount / 100);
    if (zero_cross || dial_at_zero) && pre_position != 0 {
        dial.zero_count = dial.zero_count + 1;
    }
}
