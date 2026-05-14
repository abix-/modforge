// Address: 0x14013b080
// Ghidra name: FUN_14013b080
// ============ 0x14013b080 FUN_14013b080 (size=164) ============


void FUN_14013b080(char param_1)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  undefined4 local_88 [2];

  undefined8 local_80;

  

  FUN_140139640();

  FUN_140183670();

  FUN_14013b300();

  lVar3 = FUN_14016dcf0();

  if (lVar3 != 0) {

    (**(code **)(lVar3 + 0x250))(lVar3);

  }

  FUN_14013b030();

  if (param_1 != '\0') {

    cVar1 = FUN_140139420(0x7f00);

    if (cVar1 != '\0') {

      iVar2 = FUN_140138fe0(&DAT_1403fb690);

      if (0 < iVar2) {

        FUN_14013adf0(local_88,1,2,0x7f00,0x7f00,1);

      }

      local_88[0] = 0x7f00;

      local_80 = 0;

      FUN_14013b140(local_88);

    }

  }

  return;

}




