// Address: 0x140284670
// Ghidra name: FUN_140284670
// ============ 0x140284670 FUN_140284670 (size=254) ============


int FUN_140284670(longlong param_1,undefined8 param_2,int param_3,longlong param_4,longlong param_5)



{

  longlong *plVar1;

  longlong *plVar2;

  

  if ((ulonglong)(longlong)param_3 < 0x81) {

    plVar2 = (longlong *)FUN_1401841a0(1,0xa8);

    if (plVar2 == (longlong *)0x0) {

      FUN_140284910();

      param_3 = -1;

    }

    else {

      *plVar2 = param_1;

      FUN_1402f8e20(plVar2 + 1,param_2,(longlong)param_3);

      plVar2[0x13] = param_5;

      *(int *)(plVar2 + 0x11) = param_3;

      plVar2[0x12] = param_4;

      FUN_140138fb0(param_1 + 0x88,1);

      plVar1 = plVar2;

      if (DAT_1403fddd8 != (longlong *)0x0) {

        DAT_1403fddd8[0x14] = (longlong)plVar2;

        plVar1 = DAT_1403fdde0;

      }

      DAT_1403fdde0 = plVar1;

      DAT_1403fddd8 = plVar2;

      FUN_140284910();

      FUN_14017cea0(DAT_1403fddd0);

    }

  }

  else {

    FUN_140284910();

    FUN_14012e850("Couldn\'t send rumble, size %d is greater than %d",param_3,0x80);

    param_3 = -1;

  }

  return param_3;

}




