
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

/* complete the state machine. */

void Detect_Max_Amp()
{
    switch(detect_max_amp_state)
    {
        case DMAInit:
	    detect_max_amp_state = DMAMax_Amp;
            break;
        case DMAMax_Amp:
	    detect_max_amp_state = DMAMax_Amp;
        default:
	    detect_max_amp_state = DMAInit;
            break;
    }
    switch(detect_max_amp_state)
    {
        case DMAInit:
	    max = 0;
            break;
	case DMAMax_Amp:
	    if(eq){
		max = (((~PINA & 0xF8) >> 3) > max) ? (~PINA & 0xF8) : max;
	    }
	    else{
		max = 0;
	    }
        default:
            break;
    }
}
