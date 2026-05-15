// Address: 0x14028bf60
// Ghidra name: FUN_14028bf60
// ============ 0x14028bf60 FUN_14028bf60 (size=197) ============


undefined8 FUN_14028bf60(longlong param_1,ushort *param_2,int param_3)



{

  undefined8 *puVar1;

  ushort uVar2;

  uint uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  longlong lVar6;

  uint uVar7;

  

  uVar5 = FUN_140149350();

  uVar2 = *param_2;

  if (((uVar2 != 2) && ((0x20 < uVar2 || ((0x100010110U >> ((ulonglong)uVar2 & 0x3f) & 1) == 0))))

     || (param_2[0xf] != 0)) {

    lVar6 = (longlong)param_3 * 0x98;

    uVar3 = *(uint *)(lVar6 + 0x68 + param_1);

    uVar7 = uVar3 & 1;

    if ((uVar7 == 0) || (uVar2 == *(ushort *)(lVar6 + 8 + param_1))) {

      uVar4 = *(undefined8 *)(param_2 + 4);

      puVar1 = (undefined8 *)(lVar6 + 8 + param_1);

      *puVar1 = *(undefined8 *)param_2;

      puVar1[1] = uVar4;

      uVar4 = *(undefined8 *)(param_2 + 0xc);

      puVar1 = (undefined8 *)(lVar6 + 0x18 + param_1);

      *puVar1 = *(undefined8 *)(param_2 + 8);

      puVar1[1] = uVar4;

      uVar4 = *(undefined8 *)(param_2 + 0x14);

      puVar1 = (undefined8 *)(lVar6 + 0x28 + param_1);

      *puVar1 = *(undefined8 *)(param_2 + 0x10);

      puVar1[1] = uVar4;

      uVar4 = *(undefined8 *)(param_2 + 0x1c);

      puVar1 = (undefined8 *)(lVar6 + 0x38 + param_1);

      *puVar1 = *(undefined8 *)(param_2 + 0x18);

      puVar1[1] = uVar4;

      *(undefined8 *)(lVar6 + 0x48 + param_1) = *(undefined8 *)(param_2 + 0x20);

      if (uVar7 != 0) {

        *(undefined8 *)(lVar6 + 0x78 + param_1) = uVar5;

        *(uint *)(lVar6 + 0x68 + param_1) = uVar3 | 8;

      }

      return 0;

    }

  }

  return 0xffffffff;

}




