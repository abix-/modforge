// Address: 0x1401cd800
// Ghidra name: FUN_1401cd800
// ============ 0x1401cd800 FUN_1401cd800 (size=88) ============


byte FUN_1401cd800(int param_1,int param_2,int param_3,char param_4,char param_5)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  

  bVar2 = 0;

  bVar1 = bVar2;

  if (param_1 == 1) {

    bVar1 = 0x10;

  }

  if (param_2 == 1) {

    bVar2 = 4;

  }

  bVar3 = param_3 == 1;

  if (param_5 != '\0') {

    bVar3 = (param_3 == 1) + 0x40;

  }

  return bVar3 | -(param_4 != '\0') & 0x80U | bVar1 | bVar2;

}




