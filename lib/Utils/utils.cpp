#include "utils.h"

const char* get_day_name(int day) {
    switch (day) {
        case 0: return "SUNDAY";
        case 1: return "MONDAY";
        case 2: return "TUESDAY";
        case 3: return "WEDNESDAY";
        case 4: return "THURSDAY";
        case 5: return "FRIDAY";
        case 6: return "SATURDAY";
        default: return "INVALID";
    }
}

const char* get_month_name(int month) {
    switch (month) {
        case 1: return "JAN";
        case 2: return "FEB";
        case 3: return "MAR";
        case 4: return "APR";
        case 5: return "MAY";
        case 6: return "JUN";
        case 7: return "JUL";
        case 8: return "AUG";
        case 9: return "SEP";
        case 10: return "OCT";
        case 11: return "NOV";
        case 12: return "DEC";
        default: return "INV";
    }
}

void get_day_month(int day, int month, char* buf)
{
    sprintf(buf, "%d %s", day, get_month_name(month));
}