// Address: 0x14027e070
// Ghidra name: FUN_14027e070
// ============ 0x14027e070 FUN_14027e070 (size=91) ============


void FUN_14027e070(undefined8 param_1,undefined8 param_2,char *param_3)



{

  char cVar1;

  

  cVar1 = *param_3;

  if (cVar1 == '\x01') {

    FUN_14015af40(param_2,1,param_3[1]);

    return;

  }

  if (cVar1 != '\x02') {

    if (cVar1 != '\x04') {

      FUN_14015af40(param_2,0,param_3[1]);

      return;

    }

    FUN_14015af40(param_2,4,param_3[1]);

    return;

  }

  FUN_14015af40(param_2,3,param_3[1]);

  return;

}




