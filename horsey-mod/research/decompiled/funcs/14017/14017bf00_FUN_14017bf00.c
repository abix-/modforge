// Address: 0x14017bf00
// Ghidra name: FUN_14017bf00
// ============ 0x14017bf00 FUN_14017bf00 (size=533) ============


undefined8 FUN_14017bf00(longlong param_1,longlong param_2)



{

  uint *puVar1;

  longlong lVar2;

  uint *puVar3;

  longlong lVar4;

  undefined4 uVar5;

  longlong lVar6;

  undefined8 uVar7;

  uint uVar8;

  undefined4 uVar9;

  

  if ((*(byte *)(param_1 + 0x30) & 4) != 0) {

    FUN_1401d2c00();

  }

  FUN_14017ba60(param_1 + 0x78);

  uVar9 = 0;

  *(undefined4 *)(param_1 + 0x78) = 0;

  puVar1 = *(uint **)(param_1 + 0x38);

  lVar2 = *(longlong *)(param_1 + 0x48);

  puVar3 = *(uint **)(param_2 + 0x38);

  lVar4 = *(longlong *)(param_2 + 0x48);

  uVar8 = *puVar1;

  if (((uVar8 == 0) || ((uVar8 & 0xf0000000) == 0x10000000)) &&

     ((uVar8 = uVar8 & 0xf000000, uVar8 == 0x1000000 ||

      (((uVar8 == 0xc000000 || (uVar8 == 0x2000000)) || (uVar8 == 0x3000000)))))) {

    uVar8 = *puVar3;

    if (((uVar8 == 0) || ((uVar8 & 0xf0000000) == 0x10000000)) &&

       ((uVar8 = uVar8 & 0xf000000, uVar8 == 0x1000000 ||

        (((uVar8 == 0xc000000 || (uVar8 == 0x2000000)) || (uVar8 == 0x3000000)))))) {

      if ((lVar2 == 0) || (lVar4 == 0)) {

        *(undefined4 *)(param_1 + 0x78) = 1;

      }

      else {

        lVar6 = FUN_140179b70(lVar2,lVar4,param_1 + 0x78);

        *(longlong *)(param_1 + 0xf8) = lVar6;

        if ((*(int *)(param_1 + 0x78) == 0) && (lVar6 == 0)) {

          return 0;

        }

      }

      if ((char)puVar1[1] != (char)puVar3[1]) {

        *(undefined4 *)(param_1 + 0x78) = 0;

      }

    }

    else {

      lVar6 = FUN_140179c20(lVar2,*(undefined1 *)(param_1 + 0x110),*(undefined1 *)(param_1 + 0x111),

                            *(undefined1 *)(param_1 + 0x112),*(undefined1 *)(param_1 + 0x113),puVar3

                           );

      *(longlong *)(param_1 + 0xf8) = lVar6;

      if (lVar6 == 0) {

        return 0;

      }

    }

  }

  else {

    uVar8 = *puVar3;

    if (((uVar8 == 0) || ((uVar8 & 0xf0000000) == 0x10000000)) &&

       ((uVar8 = uVar8 & 0xf000000, uVar8 == 0x1000000 ||

        (((uVar8 == 0xc000000 || (uVar8 == 0x2000000)) || (uVar8 == 0x3000000)))))) {

      uVar7 = FUN_1401aaee0(0,0,&LAB_1401aa980,&LAB_1401aa9c0,0,0);

      *(undefined8 *)(param_1 + 0x100) = uVar7;

    }

    else if (puVar1 == puVar3) {

      *(undefined4 *)(param_1 + 0x78) = 1;

    }

  }

  uVar5 = uVar9;

  if (lVar4 != 0) {

    uVar5 = *(undefined4 *)(lVar4 + 0x10);

  }

  *(undefined4 *)(param_1 + 0x118) = uVar5;

  if (lVar2 != 0) {

    uVar9 = *(undefined4 *)(lVar2 + 0x10);

  }

  *(undefined4 *)(param_1 + 0x11c) = uVar9;

  uVar7 = FUN_14021d3c0(param_1,param_2);

  return uVar7;

}




