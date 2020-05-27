//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

static unsigned char i;

/*complete the state machine*/

void Detect_EQ()
{
    switch(detect_eq_state)
    {
        case DEQInit:
	    detect_eq_state = DEQClear;
            break;
	case DEQClear:
	    if(~PINA & 0xF8){
		detect_eq_state = DEQOccur;
		i = 0;
	    }
	    else{
		detect_eq_state = DEQClear;
	    }
	    break;
	case DEQOccur:
	    if((~PINA & 0xF8) || (i < 10)){
		detect_eq_state = DEQOccur;
	    }
	    else{
		detect_eq_state = DEQClear;
	    }
        default:
            detect_eq_state = DEQInit;
            break;
    }
    switch(detect_eq_state)
    {
        case DEQInit:
	    i = 0;
            break;
	case DEQClear:
	    eq = 0;
	    break;
	case DEQOccur:
	    eq = 0x02;
	    i = ((~PINA & 0xF8) == 0) ? i + 1 : 0;
	    break;
        default:
            break;
    }
}
