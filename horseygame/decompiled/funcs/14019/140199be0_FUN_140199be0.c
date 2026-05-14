// Address: 0x140199be0
// Ghidra name: FUN_140199be0
// ============ 0x140199be0 FUN_140199be0 (size=1212) ============


ulonglong FUN_140199be0(byte *param_1,int *param_2,byte *param_3,int *param_4,int param_5)



{

  uint uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined4 uVar7;

  undefined8 uVar8;

  longlong lVar9;

  bool bVar10;

  byte bVar11;

  char cVar12;

  undefined4 uVar13;

  ulonglong uVar14;

  longlong lVar15;

  longlong lVar16;

  int iVar17;

  uint uVar18;

  int iVar19;

  int local_58 [3];

  undefined4 local_4c;

  int local_48 [3];

  undefined4 local_3c;

  

  if (param_1 == (byte *)0x0) {

    uVar14 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    return uVar14;

  }

  if (param_3 != (byte *)0x0) {

    uVar1 = *(uint *)(param_1 + 4);

    if (uVar1 == *(uint *)(param_3 + 4)) {

      if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

        iVar17 = 0;

        if ((param_5 == 0) || (param_5 == 1)) {

          iVar19 = param_5;

          if ((param_5 == 1) &&

             ((((uVar1 == 0 || ((uVar1 & 0xf0000000) != 0x10000000)) || ((char)uVar1 != '\x04')) ||

              (uVar1 == 0x16372004)))) {

            uVar14 = FUN_14012e850("Wrong format");

            return uVar14;

          }

        }

        else {

          iVar19 = iVar17;

          if (param_5 != 2) {

            uVar14 = FUN_14012e850("Parameter \'%s\' is invalid","scaleMode");

            return uVar14;

          }

        }

        if (param_2 == (int *)0x0) {

          param_2 = local_48;

          local_48[2] = *(undefined4 *)(param_1 + 8);

          local_3c = *(undefined4 *)(param_1 + 0xc);

          local_48[0] = 0;

          local_48[1] = 0;

        }

        else if (((*param_2 < 0) || (param_2[1] < 0)) ||

                ((*(int *)(param_1 + 8) < *param_2 + param_2[2] ||

                 (*(int *)(param_1 + 0xc) < param_2[3] + param_2[1])))) {

          uVar14 = FUN_14012e850("Invalid source blit rectangle");

          return uVar14;

        }

        if (param_4 == (int *)0x0) {

          param_4 = local_58;

          local_58[2] = *(undefined4 *)(param_3 + 8);

          local_4c = *(undefined4 *)(param_3 + 0xc);

          local_58[0] = 0;

          local_58[1] = 0;

        }

        else if (((*param_4 < 0) || (param_4[1] < 0)) ||

                ((*(int *)(param_3 + 8) < *param_4 + param_4[2] ||

                 (*(int *)(param_3 + 0xc) < param_4[3] + param_4[1])))) {

          uVar14 = FUN_14012e850("Invalid destination blit rectangle");

          return uVar14;

        }

        iVar4 = param_4[2];

        if ((iVar4 < 1) || (param_4[3] < 1)) {

          uVar14 = CONCAT71((uint7)(uint3)((uint)iVar4 >> 8),1);

        }

        else if ((((param_2[2] < 0x10000) && (param_2[3] < 0x10000)) && (iVar4 < 0x10000)) &&

                (param_4[3] < 0x10000)) {

          bVar10 = false;

          if ((*param_3 & 2) != 0) {

            cVar12 = FUN_140146f20(param_3);

            if (cVar12 == '\0') {

              uVar14 = FUN_14012e850("Unable to lock destination surface");

              return uVar14;

            }

            bVar10 = true;

          }

          if ((*param_1 & 2) != 0) {

            cVar12 = FUN_140146f20(param_1);

            if (cVar12 == '\0') {

              if (bVar10) {

                FUN_1401489e0(param_3);

              }

              uVar14 = FUN_14012e850("Unable to lock source surface");

              return uVar14;

            }

            iVar17 = 1;

          }

          if (iVar19 == 0) {

            bVar11 = FUN_140199ac0();

          }

          else {

            bVar11 = FUN_1401999d0(param_1,param_2,param_3,param_4);

          }

          if (bVar10) {

            FUN_1401489e0(param_3);

          }

          if (iVar17 != 0) {

            FUN_1401489e0(param_1);

          }

          uVar14 = (ulonglong)bVar11;

        }

        else {

          uVar14 = FUN_14012e850("Size too large for scaling");

        }

      }

      else {

        if (param_4 == (int *)0x0) {

          local_58[0] = 0;

          local_58[1] = 0;

          param_4 = local_58;

          local_58[2] = *(int *)(param_3 + 8);

          local_4c = *(undefined4 *)(param_3 + 0xc);

        }

        lVar15 = FUN_140145bb0(param_1,0x16161804);

        lVar16 = FUN_140145e60(param_4[2],param_4[3],0x16161804);

        if ((lVar15 == 0) || (lVar16 == 0)) {

          bVar11 = 0;

        }

        else {

          cVar12 = FUN_140199be0(lVar15,param_2,lVar16,0,param_5);

          bVar11 = 0;

          if (cVar12 != '\0') {

            uVar1 = *(uint *)(param_3 + 4);

            if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

              uVar18 = uVar1 & 0xff;

            }

            else if ((((uVar1 == 0x32595559) || (uVar1 == 0x59565955)) || (uVar1 == 0x55595659)) ||

                    (uVar1 == 0x30313050)) {

              uVar18 = 2;

            }

            else {

              uVar18 = 1;

            }

            iVar17 = *(int *)(param_3 + 0x10);

            iVar19 = *param_4;

            uVar2 = *(undefined4 *)(param_3 + 0x40);

            uVar3 = *(undefined4 *)(lVar16 + 0x10);

            iVar4 = param_4[3];

            iVar5 = param_4[1];

            iVar6 = param_4[2];

            uVar8 = *(undefined8 *)(lVar16 + 0x18);

            lVar9 = *(longlong *)(param_3 + 0x18);

            uVar7 = *(undefined4 *)(lVar16 + 4);

            uVar13 = FUN_140146bc0(param_3);

            bVar11 = FUN_140144d60(iVar6,iVar4,uVar7,0x120005a0,0,uVar8,uVar3,uVar1,uVar2,uVar13,

                                   (longlong)(iVar17 * iVar5) + (longlong)(int)(uVar18 * iVar19) +

                                   lVar9,iVar17);

          }

        }

        FUN_140146010(lVar15);

        FUN_140146010(lVar16);

        uVar14 = (ulonglong)bVar11;

      }

    }

    else {

      lVar15 = FUN_140145220(param_1,*(uint *)(param_3 + 4),*(undefined8 *)(param_3 + 0x48),

                             *(undefined4 *)(param_3 + 0x40),*(undefined4 *)(param_3 + 0x34));

      uVar14 = 0;

      if (lVar15 != 0) {

        bVar11 = FUN_140199be0(lVar15,param_2,param_3,param_4,param_5);

        FUN_140146010(lVar15);

        uVar14 = (ulonglong)bVar11;

      }

    }

    return uVar14;

  }

  uVar14 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e9c);

  return uVar14;

}




