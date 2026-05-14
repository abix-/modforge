// Address: 0x140157a10
// Ghidra name: FUN_140157a10
// ============ 0x140157a10 FUN_140157a10 (size=165) ============


ulonglong FUN_140157a10(int param_1,undefined8 *param_2,int *param_3)



{

  undefined *puVar1;

  int iVar2;

  int iVar3;

  ulonglong uVar4;

  int iVar5;

  uint uVar6;

  undefined **ppuVar7;

  

  if (param_1 != 0) {

    uVar6 = 0;

    ppuVar7 = &PTR_PTR_1403e2380;

    do {

      iVar2 = (**(code **)(*ppuVar7 + 8))();

      iVar5 = 0;

      if (0 < iVar2) {

        do {

          iVar3 = (**(code **)(*ppuVar7 + 0x50))(iVar5);

          if (iVar3 == param_1) {

            puVar1 = (&PTR_PTR_1403e2380)[(int)uVar6];

            *param_2 = puVar1;

            *param_3 = iVar5;

            return CONCAT71((int7)((ulonglong)puVar1 >> 8),1);

          }

          iVar5 = iVar5 + 1;

        } while (iVar5 < iVar2);

      }

      uVar6 = uVar6 + 1;

      ppuVar7 = ppuVar7 + 1;

    } while (uVar6 < 6);

  }

  uVar4 = FUN_14012e850("Joystick %u not found",param_1);

  return uVar4 & 0xffffffffffffff00;

}




