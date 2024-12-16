function n_meetings(start: Array<number>, end: Array<number>): number {
  let meetarray = [];

  let [last_meet_end, meet_count] = [-1, 0];

  for (let i in start) {
    meetarray.push([start[i], end[i]]);
  }

  meetarray.sort((a, b) => a[1] - b[1]);

  for (let ele of meetarray) {
    if (ele[0]) {
      last_meet_end = ele[1];
      meet_count++;
    }
  }

  return meet_count;
}
