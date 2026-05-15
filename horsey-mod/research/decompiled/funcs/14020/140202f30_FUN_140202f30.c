// Address: 0x140202f30
// Ghidra name: FUN_140202f30
// ============ 0x140202f30 FUN_140202f30 (size=140) ============


undefined1 FUN_140202f30(undefined8 param_1,undefined8 param_2,int param_3,uint *param_4)



{

  undefined1 uVar1;

  char cVar2;

  uint uVar3;

  

  if (param_3 == 0) {

    uVar3 = 2;

    cVar2 = FUN_140138c10(param_1,param_2,2);

    if (cVar2 == '\0') {

      cVar2 = FUN_140138c10(param_1,param_2,1);

      uVar3 = (uint)(cVar2 != '\0');

    }

  }

  else {

    if (param_3 != 1) {

      uVar1 = FUN_14012e850("That operation is not supported");

      return uVar1;

    }

    uVar3 = 0;

  }

  *param_4 = uVar3;

  return 1;

}




