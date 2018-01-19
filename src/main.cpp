 /**
    main.cpp
    moneyeye - manage money with command scripts.
    See docs for more info.

    Copyright 2016 Monsenhor <filipo at kobkob.org>

    This file is part of moneyeye.

    moneyeye is free software: you can redistribute it and/or modify
    it under the terms of the GNU AFFERO GENERAL PUBLIC LICENSE as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    moneyeye is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with moneyeye.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <unistd.h>
#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include "eYe/Eye.h"

#ifndef VERSION
#define VERSION 0.01
#endif

#define RECEIVE 1
#define PAY     2
#define TASK    3

using namespace std;

void printUsage (char *ar) {
   fprintf(stderr, "Usage: %s [-d] \"description frase\" [-r \"XXX,XXX.XX\"] || [-p \"XXX,XXX.XX\" ] || [-t file]\n", ar);
}

/**
 * eye is a CLI tool to process money
 * It's a proof of concept over the moneyeye lib
 *
 * Values need to be entered in the US Currency Format, like "42.67"
 * Next implementations will deal with other localization and currency.
 * The precision is default, meaning values cant be larger than long ints
 * or some like 10^14 wich is enought for normal use.
 * Next versions will implement GNU GMP libs.
 *
 * moneyeye does not process currency, locale or float values.
 * All values are long int and suposed to represent microcents of dollar.
 *
 * 1 US$ = 100000 microcents
 *
 * It's resposibility of the client using moneyeye to deal with those details.
 *
 *
 * Usage:
 *
 * eye [option] [value]
 *
 * options:
 * -d description Description for receive, pay or task file
 * -r value       Receive
 * -p value       Pay
 * -t file.eye    Do tasks using moneyeye commands
 *
 */
int main(int argc, char* argv[]) {

//    Eyeye eye;
    cout << "moneyeye " << VERSION << " - Copyleft GPL 3.0 by Monsenhor" << "\n\n";

    if (argc < 5){
	    printUsage(argv[0]);
            exit(EXIT_FAILURE);
    }

    int flags, opt;
    long double value;
    long double rValue, pValue;
    string srValue, spValue;
    char *file   = NULL;
    char *desc   = NULL;
    istringstream sr, sp;

    flags = 0;
    value = 0;
    while ((opt = getopt(argc, argv, "d:r:p:t:")) != -1) {
        switch (opt) {
        case 'd':
            desc = optarg;
            cout << "description: " << desc << "\n";
            break;
        case 'r':
            flags = RECEIVE;
            srValue.assign(optarg);
	    cout << "Receiving: " << srValue << "\n";
            sr.str(srValue);
	    //sr >> msg;
	    //cout << msg;
            sr.imbue(locale("en_US.UTF-8"));
            //while(sr >> get_money(rValue))
               cout << "rValue: " << rValue/100 << "\n";
            value = rValue * 1000;
            cout << "receiving: " << value << " microcents \n";
            break;
        case 'p':
            flags = PAY;
            spValue.assign(optarg);
	    cout << "Paying: " << spValue << "\n";
            sp.str(spValue);
	    //sr >> msg;
	    //cout << msg;
            sp.imbue(locale("en_US.UTF-8"));
            //while(sp >> get_money(pValue))
               cout << "pValue: " << pValue << "\n";
            value = pValue * 1000;
            cout << "paying: " << value << " microcents \n";
            break;
        case 't':
            flags = TASK;
            file = optarg;
            cout << "open file: " << file << "\n";
            break;
        default: /* '?' */
            printUsage(argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    if (flags == 0) {
	    printUsage(argv[0]);
            exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}


