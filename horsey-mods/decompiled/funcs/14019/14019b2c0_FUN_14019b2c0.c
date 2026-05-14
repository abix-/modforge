// Address: 0x14019b2c0
// Ghidra name: FUN_14019b2c0
// ============ 0x14019b2c0 FUN_14019b2c0 (size=1022) ============


/* WARNING: Removing unreachable block (ram,0x00014019b6a3) */

/* WARNING: Type propagation algorithm not settling */



uint * FUN_14019b2c0(undefined8 param_1)



{

  char cVar1;

  undefined1 uVar2;

  uint uVar3;

  uint uVar4;

  bool bVar5;

  bool bVar6;

  uint uVar7;

  undefined8 uVar8;

  longlong lVar9;

  undefined1 *puVar10;

  uint *puVar11;

  int *piVar12;

  undefined1 *puVar13;

  ulonglong uVar14;

  undefined1 uVar15;

  uint uVar16;

  int iVar17;

  undefined1 *puVar18;

  undefined8 uVar19;

  ulonglong uVar20;

  ulonglong uVar21;

  uint local_res10 [2];

  uint local_res18 [2];

  int local_res20 [2];

  undefined4 uVar22;

  char local_478;

  char local_477;

  char local_476;

  char local_475;

  char local_46c;

  char local_46b;

  char local_46a;

  char local_469;

  char local_45f;

  undefined1 *local_458;

  undefined1 *local_450;

  code *local_448;

  undefined1 local_438 [1024];

  

  uVar14 = 0;

  bVar5 = false;

  uVar8 = FUN_14012cba0();

  lVar9 = FUN_14012c730(param_1,&local_478,0x1a);

  if ((((((lVar9 == 0x1a) && (local_478 == -0x77)) && (local_477 == 'P')) &&

       ((local_476 == 'N' && (local_475 == 'G')))) &&

      ((local_46c == 'I' && ((local_46b == 'H' && (local_46a == 'D')))))) && (local_469 == 'R')) {

    bVar5 = false;

    if (local_45f == '\x03') {

      bVar5 = true;

    }

  }

  FUN_14012cb40(param_1,uVar8,0);

  local_res20[0] = 0;

  local_458 = &LAB_14019ae20;

  local_450 = &LAB_14019ae30;

  local_448 = FUN_14019ae00;

  local_res18[0] = 0;

  local_res10[0] = 0;

  if (bVar5) {

    FUN_1402f94c0(local_438,0xff,0x400);

    puVar13 = local_438;

    puVar10 = (undefined1 *)FUN_1401a5260(&local_458,param_1,local_res10,local_res18,puVar13,0x100);

    uVar22 = (undefined4)((ulonglong)puVar13 >> 0x20);

    iVar17 = 0;

  }

  else {

    piVar12 = local_res20;

    puVar10 = (undefined1 *)FUN_1401a5200(&local_458,param_1,local_res10,local_res18,piVar12,0);

    uVar22 = (undefined4)((ulonglong)piVar12 >> 0x20);

    iVar17 = local_res20[0];

  }

  uVar7 = local_res18[0];

  uVar16 = local_res10[0];

  if (puVar10 == (undefined1 *)0x0) {

    FUN_14012cb40(param_1,uVar8,0);

    return (uint *)0x0;

  }

  if (bVar5) {

    puVar11 = (uint *)FUN_140145bc0(local_res10[0],local_res18[0],0x13000801,puVar10,

                                    CONCAT44(uVar22,local_res10[0]));

    if (puVar11 != (uint *)0x0) {

      bVar5 = false;

      uVar21 = 0xffffffff;

      bVar6 = false;

      piVar12 = (int *)FUN_140145d20(puVar11);

      if ((piVar12 != (int *)0x0) && (0 < *piVar12)) {

        lVar9 = *(longlong *)(piVar12 + 2);

        uVar20 = uVar14;

        puVar10 = local_438 + 2;

        do {

          *(undefined1 *)(uVar14 + lVar9) = puVar10[-2];

          *(undefined1 *)(uVar14 + *(longlong *)(piVar12 + 2) + 1) = puVar10[-1];

          *(undefined1 *)(uVar14 + *(longlong *)(piVar12 + 2) + 2) = *puVar10;

          *(undefined1 *)(uVar14 + *(longlong *)(piVar12 + 2) + 3) = puVar10[1];

          lVar9 = *(longlong *)(piVar12 + 2);

          cVar1 = *(char *)(uVar14 + lVar9 + 3);

          if (cVar1 != -1) {

            if ((cVar1 != '\0') || (bVar5)) {

              bVar6 = true;

            }

            else {

              bVar5 = true;

              uVar21 = uVar20;

            }

          }

          uVar16 = (int)uVar20 + 1;

          uVar20 = (ulonglong)uVar16;

          uVar14 = uVar14 + 4;

          puVar10 = puVar10 + 4;

        } while ((int)uVar16 < *piVar12);

        if (bVar6) {

          FUN_140148450(puVar11,1);

          *puVar11 = *puVar11 & 0xfffffffe;

          return puVar11;

        }

        if (bVar5) {

          FUN_140148630(puVar11,CONCAT71((int7)(uVar14 >> 8),1),uVar21);

          *puVar11 = *puVar11 & 0xfffffffe;

          return puVar11;

        }

      }

      goto LAB_14019b680;

    }

    goto LAB_14019b68a;

  }

  if ((iVar17 - 1U & 0xfffffffd) == 0) {

    if (iVar17 == 4) goto LAB_14019b600;

    uVar19 = 0x13000801;

    if (iVar17 == 3) {

      uVar19 = 0x17101803;

    }

  }

  else {

    if (iVar17 != 4) {

      if (iVar17 == 2) {

        uVar14 = (ulonglong)local_res10[0];

        puVar11 = (uint *)FUN_140145e60(uVar14,local_res18[0],0x16762004);

        if (puVar11 != (uint *)0x0) {

          uVar3 = puVar11[2];

          uVar4 = puVar11[4];

          puVar13 = *(undefined1 **)(puVar11 + 6);

          if (0 < (int)uVar7) {

            uVar21 = (ulonglong)uVar7;

            puVar18 = puVar10;

            do {

              uVar20 = uVar14;

              if (0 < (int)uVar16) {

                do {

                  uVar15 = *puVar18;

                  uVar2 = puVar18[1];

                  puVar18 = puVar18 + 2;

                  *puVar13 = uVar15;

                  puVar13[1] = uVar15;

                  puVar13[2] = uVar15;

                  puVar13[3] = uVar2;

                  puVar13 = puVar13 + 4;

                  uVar20 = uVar20 - 1;

                } while (uVar20 != 0);

              }

              puVar13 = puVar13 + (int)(uVar4 + uVar3 * -4);

              uVar21 = uVar21 - 1;

            } while (uVar21 != 0);

          }

          FUN_140160120(puVar10);

          return puVar11;

        }

      }

      else {

        FUN_14012e850("Unknown image format: %d",iVar17);

      }

      goto LAB_14019b68a;

    }

LAB_14019b600:

    uVar19 = 0x16762004;

  }

  puVar11 = (uint *)FUN_140145bc0(local_res10[0],local_res18[0],uVar19,puVar10,

                                  CONCAT44(uVar22,iVar17 * local_res10[0]));

  if (puVar11 != (uint *)0x0) {

    if (((puVar11[1] == 0x13000801) &&

        (piVar12 = (int *)FUN_140145d20(puVar11), piVar12 != (int *)0x0)) && (0 < *piVar12)) {

      do {

        lVar9 = (longlong)(int)uVar14;

        uVar15 = (undefined1)uVar14;

        *(undefined1 *)(*(longlong *)(piVar12 + 2) + lVar9 * 4) = uVar15;

        *(undefined1 *)(*(longlong *)(piVar12 + 2) + 1 + lVar9 * 4) = uVar15;

        *(undefined1 *)(*(longlong *)(piVar12 + 2) + 2 + lVar9 * 4) = uVar15;

        uVar16 = (int)uVar14 + 1;

        uVar14 = (ulonglong)uVar16;

      } while ((int)uVar16 < *piVar12);

    }

LAB_14019b680:

    *puVar11 = *puVar11 & 0xfffffffe;

    return puVar11;

  }

LAB_14019b68a:

  FUN_140160120(puVar10);

  FUN_14012cb40(param_1,uVar8,0);

  return (uint *)0x0;

}




