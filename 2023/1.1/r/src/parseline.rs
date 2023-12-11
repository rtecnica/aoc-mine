pub fn pars_cal_val(line: &str) -> u32 {
    let mut firstdigit = 'X';
    let mut secondigit = 'X';

    for c in line.chars() {
        if c.is_digit(10) {
            if firstdigit.is_digit(10) {
                secondigit = c;
            } else {
                firstdigit = c;
            }
        }
    }

    let firstdigit = firstdigit.to_digit(10);
    let secondigit = secondigit.to_digit(10);

    match (firstdigit, secondigit) {
        (None, None) => 0,
        (Some(f), None) => f * 10 + f,
        (None, _) => 0,
        (Some(f), Some(s)) => f * 10 + s,
    }
}
