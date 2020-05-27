
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

static unsigned char i;

/*complete the state machine*/

void Ping()
{
    switch(ping_state)
    {
        case PInit:
	    ping_state = PHigh;
            break;
	case PHigh:
	    ping_state = PLow;
	    i = 0;
	    break;
	case PLow:
	    ping_state = (i <= 9) ? PLow : PHigh;
	    i++;
	    break;
        default:
            ping_state = PInit;
            break;
    }
    switch(ping_state)
    {
        case PInit:
            break;
	case PHigh:
	    ping = 0x01;
	    break;
	case PLow:
	    ping = 0x00;
	    break;
        default:
            break;
    }
}
