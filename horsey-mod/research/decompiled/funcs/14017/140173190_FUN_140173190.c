// Address: 0x140173190
// Ghidra name: FUN_140173190
// ============ 0x140173190 FUN_140173190 (size=1035) ============


undefined4 FUN_140173190(longlong param_1,int param_2,char param_3)



{

  uint *puVar1;

  bool bVar2;

  char cVar3;

  int iVar4;

  uint *puVar5;

  undefined8 *puVar6;

  longlong lVar7;

  uint *puVar8;

  uint uVar9;

  uint uVar10;

  uint *puVar12;

  uint *puVar13;

  int local_res10;

  undefined4 local_48;

  undefined4 local_44;

  uint *puVar11;

  

  puVar13 = (uint *)0x0;

  puVar12 = (uint *)0x0;

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar3 = FUN_1401aa7c0(param_1,1), cVar3 == '\0')))) {

    FUN_14012e850("Invalid window");

    return 0;

  }

  lVar7 = DAT_1403fc410;

  *(undefined1 *)(param_1 + 0x5d) = 0;

  *(undefined1 *)(param_1 + 0x10d) = 0;

  if ((*(char *)(param_1 + 0x10f) == '\0') && (*(char *)(param_1 + 0x109) == '\0')) {

    local_res10 = param_2;

    if (param_2 == 0) goto LAB_14017324e;

    puVar5 = (uint *)FUN_14016dd30(param_1);

    if (puVar5 == (uint *)0x0) goto LAB_140173443;

LAB_14017328b:

    puVar12 = (uint *)FUN_14016e1f0(param_1);

    lVar7 = DAT_1403fc410;

    if (puVar12 == (uint *)0x0) {

      *(undefined8 *)(param_1 + 200) = 0;

      *(undefined8 *)(param_1 + 0xd0) = 0;

      *(undefined8 *)(param_1 + 0xd8) = 0;

      *(undefined8 *)(param_1 + 0xe0) = 0;

      *(undefined8 *)(param_1 + 0xe8) = 0;

    }

    else {

      *(undefined1 *)(param_1 + 0x5d) = 1;

    }

  }

  else {

    local_res10 = 0;

LAB_14017324e:

    uVar9 = *(uint *)(lVar7 + 0x328);

    if ((int)uVar9 < 1) {

LAB_140173284:

      puVar5 = puVar13;

    }

    else {

      puVar6 = *(undefined8 **)(lVar7 + 0x330);

      puVar8 = puVar13;

      puVar11 = puVar13;

      do {

        uVar10 = (uint)puVar11;

        puVar5 = (uint *)*puVar6;

        if (*(longlong *)(puVar5 + 0x1a) == param_1) break;

        uVar10 = uVar10 + 1;

        puVar11 = (uint *)(ulonglong)uVar10;

        puVar8 = (uint *)((longlong)puVar8 + 1);

        puVar6 = puVar6 + 1;

      } while ((longlong)puVar8 < (longlong)(int)uVar9);

      if (uVar10 == uVar9) goto LAB_140173284;

    }

    if (local_res10 != 0) goto LAB_14017328b;

  }

  if ((puVar5 != (uint *)0x0) && (puVar8 = puVar13, puVar11 = puVar13, 0 < *(int *)(lVar7 + 0x328)))

  {

    do {

      puVar1 = *(uint **)((longlong)puVar11 + *(longlong *)(lVar7 + 0x330));

      if ((puVar1 != puVar5) && (*(longlong *)(puVar1 + 0x1a) == param_1)) {

        FUN_140170570(puVar1,0);

        lVar7 = DAT_1403fc410;

        puVar1[0x1a] = 0;

        puVar1[0x1b] = 0;

      }

      uVar9 = (int)puVar8 + 1;

      puVar8 = (uint *)(ulonglong)uVar9;

      puVar11 = puVar11 + 2;

    } while ((int)uVar9 < *(int *)(lVar7 + 0x328));

  }

  if (local_res10 == 0) {

    bVar2 = false;

    if (puVar5 != (uint *)0x0) {

      *(undefined1 *)(puVar5 + 0x19) = 0;

      FUN_140170570(puVar5,0);

      lVar7 = DAT_1403fc410;

    }

    if (param_3 != '\0') {

      if (*(longlong *)(lVar7 + 0x100) == 0) {

        bVar2 = true;

      }

      else {

        puVar12 = puVar5;

        if (((puVar5 != (uint *)0x0) ||

            (puVar12 = (uint *)FUN_14016dd30(param_1), lVar7 = DAT_1403fc410, puVar12 != (uint *)0x0

            )) && (iVar4 = (**(code **)(lVar7 + 0x100))(lVar7,param_1,puVar12,0),

                  lVar7 = DAT_1403fc410, iVar4 != 1)) {

          if (iVar4 == 0) {

            return 0;

          }

          goto LAB_140173525;

        }

      }

      if ((*(byte *)(param_1 + 0x48) & 1) != 0) {

        FUN_1401cda90(param_1,0x218,0,0);

        lVar7 = DAT_1403fc410;

      }

    }

LAB_140173525:

    if ((*(byte *)(param_1 + 0x48) & 1) == 0) {

      if (puVar5 != (uint *)0x0) {

        puVar5[0x1a] = 0;

        puVar5[0x1b] = 0;

      }

      cVar3 = FUN_1401702e0(lVar7);

      if (cVar3 == '\0') {

        FUN_1401cda90(param_1,0x205,*(undefined4 *)(param_1 + 0x6c),*(undefined4 *)(param_1 + 0x70))

        ;

        if (bVar2) {

          FUN_1401cda90(param_1,0x206,*(undefined4 *)(param_1 + 0x74),

                        *(undefined4 *)(param_1 + 0x78));

        }

        else {

LAB_140173428:

          FUN_14016f9c0(param_1);

        }

      }

    }

  }

  else {

    bVar2 = false;

    if ((*(longlong *)(puVar5 + 0x1a) != 0) && (*(longlong *)(puVar5 + 0x1a) != param_1)) {

      FUN_14016f4f0();

    }

    *(undefined1 *)(puVar5 + 0x19) = *(undefined1 *)(param_1 + 0x5d);

    cVar3 = FUN_140170570(puVar5,puVar12);

    if (cVar3 == '\0') {

LAB_140173389:

      FUN_140173190(param_1,0,param_3);

      return 0;

    }

    if (param_3 != '\0') {

      if (*(code **)(DAT_1403fc410 + 0x100) == (code *)0x0) {

        bVar2 = true;

      }

      else {

        iVar4 = (**(code **)(DAT_1403fc410 + 0x100))(DAT_1403fc410,param_1,puVar5,local_res10);

        if (iVar4 != 1) {

          if (iVar4 == 0) {

            *(undefined1 *)(puVar5 + 0x19) = 0;

            goto LAB_140173389;

          }

          goto LAB_1401733ba;

        }

      }

      if ((*(byte *)(param_1 + 0x48) & 1) == 0) {

        FUN_1401cda90(param_1,0x217,0,0);

      }

    }

LAB_1401733ba:

    lVar7 = DAT_1403fc410;

    if ((*(byte *)(param_1 + 0x48) & 1) != 0) {

      *(longlong *)(puVar5 + 0x1a) = param_1;

      cVar3 = FUN_1401702e0(lVar7);

      if (cVar3 == '\0') {

        if (puVar12 == (uint *)0x0) {

          uVar9 = puVar5[10];

          uVar10 = puVar5[0xb];

          puVar12 = puVar5;

        }

        else {

          uVar9 = puVar12[2];

          uVar10 = puVar12[3];

        }

        FUN_14016d280(*puVar12,&local_48);

        if ((*(uint *)(param_1 + 0x20) == uVar9) && (*(uint *)(param_1 + 0x24) == uVar10)) {

          FUN_1401cda90(param_1,0x205,local_48,local_44);

          if (!bVar2) goto LAB_140173428;

        }

        else {

          FUN_1401cda90(param_1,0x205,local_48,local_44);

        }

        FUN_1401cda90(param_1,0x206,uVar9,uVar10);

      }

    }

  }

  if (((puVar5 != (uint *)0x0) && ((*(byte *)(param_1 + 0x48) & 1) != 0)) &&

     (puVar13 = (uint *)0x0, *(char *)(param_1 + 0x5d) != '\0')) {

    puVar13 = (uint *)(ulonglong)*puVar5;

  }

LAB_140173443:

  *(int *)(param_1 + 0x60) = (int)puVar13;

  return 1;

}




