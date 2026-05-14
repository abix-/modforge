// Address: 0x140175b00
// Ghidra name: FUN_140175b00
// ============ 0x140175b00 FUN_140175b00 (size=110) ============


undefined4 FUN_140175b00(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (param_1 != 0) {

    iVar1 = FUN_14021aed0();

    iVar3 = 0;

    if (0 < iVar1) {

      do {

        iVar2 = FUN_14021ac70(iVar3);

        if (iVar2 == param_1) {

          *param_2 = iVar3;

          return 1;

        }

        iVar3 = iVar3 + 1;

      } while (iVar3 < iVar1);

    }

  }

  FUN_14012e850("Haptic device %u not found",param_1);

  return 0;

}




