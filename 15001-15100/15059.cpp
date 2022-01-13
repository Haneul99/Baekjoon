﻿#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>


using namespace std;


int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int chicken, beef, pasta;
	int cnum, bnum, pnum;
	scanf("%d%d%d", &chicken, &beef, &pasta);
	scanf("%d%d%d", &cnum, &bnum, &pnum);
	int ans = 0;
	if (cnum > chicken) ans += cnum - chicken;
	if (bnum > beef) ans += bnum - beef;
	if (pnum > pasta) ans += pnum - pasta;

	printf("%d\n", ans);
}


/*
15059. Hard choice
https://www.acmicpc.net/problem/15059

문제
In long flights, airlines offer hot meals. Usually the flight attendants push carts containing the meals down along the aisles of the plane. When a cart reaches your row, you are asked right away: “Chicken, beef, or pasta?” You know your choices, but you have only a few seconds to choose and you don’t know how your choice will look like because your neighbor hasn’t opened his wrap yet. . .

The flight attendant in this flight decided to change the procedure. First she will ask all passengers what choice of meal they would prefer, and then she will check if the number of meals available in this flight for each choice are enough.

As an example, consider that the available number of meals for chicken, beef and pasta are respectively (80, 20, 40), while the number of passenger’s choices for chicken, beef and pasta are respectively (45, 23, 48). In this case, eleven people will surely not receive their selection for a meal, since three passengers who wanted beef and eight passengers who wanted pasta cannot be pleased.

Given the quantity of meals available for each choice and the number of meals requested for each choice, could you please help the flight attendant to determine how many passengers will surely not receive their selection for a meal?

입력
The first line contains three integers Ca, Ba and Pa (0 ≤ Ca, Ba, Pa ≤ 100), representing respectively the number of meals available for chicken, beef and pasta. The second line contains three integers Cr, Br and Pr (0 ≤ Cr, Br, Pr ≤ 100), indicating respectively the number of meals requested for chicken, beef and pasta.

출력
Output a single line with an integer representing the number of passengers that will surely not receive their selection for a meal.
*/