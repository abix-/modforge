// Address: 0x14016dd30
// Ghidra name: FUN_14016dd30
// ============ 0x14016dd30 FUN_14016dd30 (size=278) ============


undefined8 FUN_14016dd30(longlong param_1)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  char cVar5;

  int iVar6;

  longlong lVar7;

  undefined8 uVar8;

  bool bVar9;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar5 = FUN_1401aa7c0(param_1,1), cVar5 != '\0')))) {

    iVar6 = *(int *)(param_1 + 200);

    if ((iVar6 == 0) && (iVar6 = *(int *)(param_1 + 0x68), iVar6 == 0)) {

      bVar9 = *(char *)(param_1 + 0x10c) == '\0';

      lVar7 = 0x94;

      if (bVar9) {

        lVar7 = 0x20;

      }

      uVar1 = *(undefined4 *)(lVar7 + param_1);

      lVar7 = 0x98;

      if (bVar9) {

        lVar7 = 0x24;

      }

      bVar9 = *(char *)(param_1 + 0x10b) == '\0';

      uVar2 = *(undefined4 *)(lVar7 + param_1);

      lVar7 = 0x8c;

      if (bVar9) {

        lVar7 = 0x18;

      }

      uVar3 = *(undefined4 *)(lVar7 + param_1);

      lVar7 = 0x90;

      if (bVar9) {

        lVar7 = 0x1c;

      }

      uVar4 = *(undefined4 *)(lVar7 + param_1);

      iVar6 = FUN_140169c90(uVar3,uVar4);

      if ((iVar6 == 0) && (iVar6 = FUN_140169d40(uVar3,uVar4,uVar1,uVar2), iVar6 == 0)) {

        iVar6 = FUN_14016dba0();

      }

    }

    uVar8 = FUN_14016dd00(iVar6);

    return uVar8;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




