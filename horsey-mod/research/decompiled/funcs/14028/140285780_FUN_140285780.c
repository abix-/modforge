// Address: 0x140285780
// Ghidra name: FUN_140285780
// ============ 0x140285780 FUN_140285780 (size=121) ============


void FUN_140285780(undefined8 param_1,char *param_2)



{

  char cVar1;

  undefined8 uVar2;

  

  cVar1 = *param_2;

  if (cVar1 != '\0') {

    if (cVar1 == '\x01') {

      uVar2 = 3;

      goto LAB_1402857ae;

    }

    if (cVar1 != -1) {

      uVar2 = 1;

      goto LAB_1402857ae;

    }

  }

  uVar2 = 0;

LAB_1402857ae:

  cVar1 = param_2[1];

  if (cVar1 == '\0') {

    FUN_14015af40(param_1,uVar2,10);

    return;

  }

  if (cVar1 != '\x01') {

    if (cVar1 != '\x02') {

      FUN_14015af40(param_1,uVar2,100);

      return;

    }

    FUN_14015af40(param_1,uVar2,0x46);

    return;

  }

  FUN_14015af40(param_1,uVar2,0x28);

  return;

}




