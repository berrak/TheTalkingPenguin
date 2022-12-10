// ------------------------------------------------------------------
// HELPERS     HELPERS     HELPERS     HELPERS     HELPERS
// ------------------------------------------------------------------

void sayClock(int hour, int minute, bool clock_24h_format) {

    voice.say(spPAUSE2);

    sayGreeting(hour);

    voice.say(spPAUSE1);
    voice.say(spc_THE);
    voice.say(spc_TIME);
    voice.say(spc_IS);

    switch (hour) {

    case 0:
        voice.say(spc_OH);
        sayMinute(minute);
        break;

    case 1:
        voice.say(spc_ONE);
        sayMinute(minute);
        break;

    case 2:
        voice.say(spc_TWO);
        sayMinute(minute);
        break;

    case 3:
        voice.say(spc_THREE);
        sayMinute(minute);
        break;

    case 4:
        voice.say(spc_FOUR);
        sayMinute(minute);
        break;

    case 5:
        voice.say(spc_FIVE);
        sayMinute(minute);
        break;

    case 6:
        voice.say(spc_SIX);
        sayMinute(minute);
        break;

    case 7:
        voice.say(spc_SEVEN);
        sayMinute(minute);
        break;

    case 8:
        voice.say(spc_EIGHT);
        sayMinute(minute);
        break;

    case 9:
        voice.say(spc_NINE);
        sayMinute(minute);
        break;

    case 10:
        voice.say(spc_TEN);
        sayMinute(minute);
        break;

    case 11:
        voice.say(spc_ELEVEN);
        sayMinute(minute);
        break;

    case 12:
        voice.say(spc_TWELVE);
        sayMinute(minute);
        break;

    case 13:
        if (clock_24h_format == true) {
            voice.say(spc_THIRTEEN);
        } else {
            voice.say(spc_ONE);
        }
        sayMinute(minute);
        break;

    case 14:
        if (clock_24h_format == true) {
            voice.say(spc_FOURTEEN);
        } else {
            voice.say(spc_TWO);
        }
        sayMinute(minute);
        break;

    case 15:
        if (clock_24h_format == true) {
            voice.say(spc_FIFTEEN);
        } else {
            voice.say(spc_THREE);
        }
        sayMinute(minute);
        break;

    case 16:
        if (clock_24h_format == true) {
            voice.say(spc_SIXTEEN);
        } else {
            voice.say(spc_FOUR);
        }
        sayMinute(minute);
        break;

    case 17:
        if (clock_24h_format == true) {
            voice.say(spc_SEVENTEEN);
        } else {
            voice.say(spc_FIVE);
        }
        sayMinute(minute);
        break;

    case 18:
        if (clock_24h_format == true) {
            voice.say(spc_EIGHTEEN);
        } else {
            voice.say(spc_SIX);
        }
        sayMinute(minute);
        break;

    case 19:
        if (clock_24h_format == true) {
            voice.say(spc_NINETEEN);
        } else {
            voice.say(spc_SEVEN);
        }
        sayMinute(minute);
        break;

    case 20:
        if (clock_24h_format == true) {
            voice.say(spc_TWENTY);
        } else {
            voice.say(spc_EIGHT);
        }
        sayMinute(minute);
        break;

    case 21:
        if (clock_24h_format == true) {
            voice.say(spc_TWENTY);
            voice.say(spc_ONE);
        } else {
            voice.say(spc_NINE);
        }
        sayMinute(minute);
        break;

    case 22:
        if (clock_24h_format == true) {
            voice.say(spc_TWENTY);
            voice.say(spc_TWO);
        } else {
            voice.say(spc_TEN);
        }
        sayMinute(minute);
        break;

    case 23:
        if (clock_24h_format == true) {
            voice.say(spc_TWENTY);
            voice.say(spc_THREE);
        } else {
            voice.say(spc_ELEVEN);
        }
        sayMinute(minute);
        break;

    default:
        voice.say(sp2_DANGER);
        voice.say(sp2_DANGER);
        voice.say(sp2_RED);
        voice.say(sp2_ALERT);
        break;
    }

    say12hClock(hour, clock_24h_format);

    voice.say(spPAUSE1);
}

void sayGreeting(int hour) {

    voice.say(spc_GOOD);

    // Silence between 0 and 6AM
    if (hour >= 6 && hour < 12) {
        voice.say(spc_MORNING);
    } else if (hour >= 12 && hour < 18) {
        voice.say(spc_AFTERNOON);
    } else if (hour >= 18) {
        voice.say(spc_EVENING);
    }
}

void say12hClock(int hour, bool clock_24h_format) {

    if (clock_24h_format == false) {

        // Silence between 0 and 6AM
        if (hour >= 6 && hour < 12) {
            voice.say(spc_A_M_);
        } else if (hour >= 12 && hour < 24) {
            voice.say(spc_P_M_);
        }
    }
}

// A very long and tedious function ...
void sayMinute(int minute) {

    switch (minute) {

    case 0:
        voice.say(spc_OH);
        break;

    case 1:
        voice.say(spc_ONE);
        break;

    case 2:
        voice.say(spc_TWO);
        break;

    case 3:
        voice.say(spc_THREE);
        break;

    case 4:
        voice.say(spc_FOUR);
        break;

    case 5:
        voice.say(spc_FIVE);
        break;

    case 6:
        voice.say(spc_SIX);
        break;

    case 7:
        voice.say(spc_SEVEN);
        break;

    case 8:
        voice.say(spc_EIGHT);
        break;

    case 9:
        voice.say(spc_NINE);
        break;

    case 10:
        voice.say(spc_TEN);
        break;

    case 11:
        voice.say(spc_ELEVEN);
        break;

    case 12:
        voice.say(spc_TWELVE);
        break;

    case 13:
        voice.say(spc_THIRTEEN);
        break;

    case 14:
        voice.say(spc_FOURTEEN);
        break;

    case 15:
        voice.say(spc_FIFTEEN);
        break;

    case 16:
        voice.say(spc_SIXTEEN);
        break;

    case 17:
        voice.say(spc_SEVENTEEN);
        break;

    case 18:
        voice.say(spc_EIGHTEEN);
        break;

    case 19:
        voice.say(spc_NINETEEN);
        break;

    case 20:
        voice.say(spc_TWENTY);
        break;

    case 21:
        voice.say(spc_TWENTY);
        voice.say(spc_ONE);
        break;

    case 22:
        voice.say(spc_TWENTY);
        voice.say(spc_TWO);
        break;

    case 23:
        voice.say(spc_TWENTY);
        voice.say(spc_THREE);
        break;

    case 24:
        voice.say(spc_TWENTY);
        voice.say(spc_FOUR);
        break;

    case 25:
        voice.say(spc_TWENTY);
        voice.say(spc_FIVE);
        break;

    case 26:
        voice.say(spc_TWENTY);
        voice.say(spc_SIX);
        break;

    case 27:
        voice.say(spc_TWENTY);
        voice.say(spc_SEVEN);
        break;

    case 28:
        voice.say(spc_TWENTY);
        voice.say(spc_EIGHT);
        break;

    case 29:
        voice.say(spc_TWENTY);
        voice.say(spc_NINE);
        break;

    case 30:
        voice.say(spc_THIRTY);
        break;

    case 31:
        voice.say(spc_THIRTY);
        voice.say(spc_ONE);
        break;

    case 32:
        voice.say(spc_THIRTY);
        voice.say(spc_TWO);
        break;

    case 33:
        voice.say(spc_THIRTY);
        voice.say(spc_THREE);
        break;

    case 34:
        voice.say(spc_THIRTY);
        voice.say(spc_FOUR);
        break;

    case 35:
        voice.say(spc_THIRTY);
        voice.say(spc_FIVE);
        break;

    case 36:
        voice.say(spc_THIRTY);
        voice.say(spc_SIX);
        break;

    case 37:
        voice.say(spc_THIRTY);
        voice.say(spc_SEVEN);
        break;

    case 38:
        voice.say(spc_THIRTY);
        voice.say(spc_EIGHT);
        break;

    case 39:
        voice.say(spc_THIRTY);
        voice.say(spc_NINE);
        break;

    case 40:
        voice.say(spc_FOURTY);
        break;

    case 41:
        voice.say(spc_FOURTY);
        voice.say(spc_ONE);
        break;

    case 42:
        voice.say(spc_FOURTY);
        voice.say(spc_TWO);
        break;

    case 43:
        voice.say(spc_FOURTY);
        voice.say(spc_THREE);
        break;

    case 44:
        voice.say(spc_FOURTY);
        voice.say(spc_FOUR);
        break;

    case 45:
        voice.say(spc_FOURTY);
        voice.say(spc_FIVE);
        break;

    case 46:
        voice.say(spc_FOURTY);
        voice.say(spc_SIX);
        break;

    case 47:
        voice.say(spc_FOURTY);
        voice.say(spc_SEVEN);
        break;

    case 48:
        voice.say(spc_FOURTY);
        voice.say(spc_EIGHT);
        break;

    case 49:
        voice.say(spc_FOURTY);
        voice.say(spc_NINE);
        break;

    case 50:
        voice.say(spc_FIFTY);
        break;

    case 51:
        voice.say(spc_FIFTY);
        voice.say(spc_ONE);
        break;

    case 52:
        voice.say(spc_FIFTY);
        voice.say(spc_TWO);
        break;

    case 53:
        voice.say(spc_FIFTY);
        voice.say(spc_THREE);
        break;

    case 54:
        voice.say(spc_FIFTY);
        voice.say(spc_FOUR);
        break;

    case 55:
        voice.say(spc_FIFTY);
        voice.say(spc_FIVE);
        break;

    case 56:
        voice.say(spc_FIFTY);
        voice.say(spc_SIX);
        break;

    case 57:
        voice.say(spc_FIFTY);
        voice.say(spc_SEVEN);
        break;

    case 58:
        voice.say(spc_FIFTY);
        voice.say(spc_EIGHT);
        break;

    case 59:
        voice.say(spc_FIFTY);
        voice.say(spc_NINE);
        break;

    default:
        break;
    }
}
