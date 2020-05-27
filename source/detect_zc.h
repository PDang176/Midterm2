
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

static unsigned char prev;

/*complete the state machine*/

void Detect_ZC()
{
    switch(detect_zc_state)
    {
        case DZCInit:
	    detect_zc_state = DZCClear;
            break;
	case DZCClear:
	    if(eq){
		detect_zc_state = DZCOccur;
		prev = ~PINA & 0x07;
	    }
	    else{
		detect_zc_state = DZCClear;
	    }
	    break;
	case DZCOccur:
	    if(eq){
                detect_zc_state = DZCOccur;
                prev = ~PINA & 0x07;
            }
            else{
                detect_zc_state = DZCClear;
            }
        default:
            detect_zc_state = DZCInit;
            break;
    }
    switch(detect_zc_state)
    {
        case DZCInit:
            break;
	case DZCClear:
	    zc = 0x00;
	    break;
	case DZCOccur:
	    if((~PINA & 0x03) == (prev & 0x03)){
		if((~PINA & 0x04) != (prev & 0x04)){
			zc = 0x04;
		}
		else{
			zc = 0x00;
		}
	    }
    	    else{
		zc = 0x00;
	    }
        default:
            break;
    }
}
