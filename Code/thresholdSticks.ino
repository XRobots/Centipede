int thresholdStick (int pos) {
  
    // get zero centre position
    pos = pos - 1500;  

    // threshold value for control sticks 
    if (pos > 100) {
      pos = pos -100;
    }
    else if (pos < -100) {
      pos = pos +100;
    }
    else {
      pos = 0;
    }

    pos = map(pos, -370,370,-255,255);
    pos = constrain(pos,-255,255);

    return pos;
}


