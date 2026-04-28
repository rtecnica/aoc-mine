pub fn oom(number: u64) -> u32 {
    let mut ret = 1;
    let mut rem = number / 10;
    while rem != 0 {
        ret = ret + 1;
        rem = rem / 10;
    }
    return ret;
}

pub fn find_divisors(target: u32) -> (u32, Vec<u32>) {
    let mut cnt = 0;
    let mut i = 2;
    let mut divs = vec![];
    let upper_bound = (target as f32).sqrt() as u32;
    while i <= upper_bound {
        if target % i == 0 {
            divs.push(i);
            cnt = cnt + 1;
            if i != (target / i) {
                divs.push(target / i);
                cnt = cnt + 1;
            }
        }
        i = i + 1;
    }
    divs.sort();
    return (cnt, divs);
}

pub fn has_repeat(number: u64) -> u32 {
    let order = oom(number);
    let mut repeat_amount = 0;
    let (cnt, divs) = find_divisors(order);
    if cnt == 0 && order > 1 {
        let divider = (1..order)
            .map(|x| (10 as u64).pow(x) as u64)
            .fold(1, |x, y| x + y);
        if number % divider == 0 {
            println!("{} {}", number, divider);
            return order;
        }
    }
    for div in divs.iter() {
        let divider = (1..*div)
            .map(|x| (10 as u32).pow((order / div) * x) as u32)
            .fold(1, |x, y| x + y);
        if number % (divider as u64) == 0 {
            repeat_amount = *div;
        }
    }
    return repeat_amount;
}
