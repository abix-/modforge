// Address: 0x1401bb360
// Ghidra name: FUN_1401bb360
// ============ 0x1401bb360 FUN_1401bb360 (size=485) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



bool FUN_1401bb360(undefined8 *param_1,longlong param_2,undefined8 param_3,undefined8 param_4,

                  uint *param_5)



{

  uint uVar1;

  code *pcVar2;

  undefined8 uVar3;

  longlong lVar4;

  char cVar5;

  ulonglong uVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  uint local_res8 [2];

  undefined8 auStack_130 [5];

  uint local_108 [6];

  int local_f0;

  int local_e0;

  int local_dc;

  int local_bc;

  int local_74;

  

  auStack_130[0] = 0x1401bb39f;

  (*(code *)param_1[300])(param_3,local_108);

  if ((((((local_108[3] != 0) || (*(int *)(param_2 + 0x10) == 0)) &&

        ((local_108[2] != 0 || (*(int *)(param_2 + 0xc) == 0)))) &&

       ((local_dc != 0 || (*(int *)(param_2 + 0x30) == 0)))) &&

      ((local_74 != 0 || (*(int *)(param_2 + 0x98) == 0)))) &&

     ((((local_e0 != 0 || (*(int *)(param_2 + 0x2c) == 0)) &&

       ((local_f0 != 0 || (*(int *)(param_2 + 0x1c) == 0)))) &&

      ((local_bc != 0 || (*(int *)(param_2 + 0x50) == 0)))))) {

    if (*(char *)(param_2 + 0x240) != '\0') {

      auStack_130[0] = 0x1401bb430;

      cVar5 = FUN_1401bdf00(param_1,param_2,param_3,local_108);

      if (cVar5 == '\0') {

        return false;

      }

    }

    auStack_130[0] = 0x1401bb449;

    cVar5 = FUN_1401b5110(param_1,param_2,param_3,param_4);

    if (cVar5 != '\0') {

      auStack_130[0] = 0x1401bb467;

      (*(code *)param_1[0x12d])(param_3,local_res8,0);

      uVar6 = (ulonglong)local_res8[0] * 0x18 + 0xf;

      if (uVar6 <= (ulonglong)local_res8[0] * 0x18) {

        uVar6 = 0xffffffffffffff0;

      }

      auStack_130[0] = 0x1401bb491;

      lVar4 = -(uVar6 & 0xfffffffffffffff0);

      pcVar2 = (code *)param_1[0x12d];

      *(undefined8 *)((longlong)auStack_130 + lVar4) = 0x1401bb4af;

      (*pcVar2)(param_3,local_res8,(longlong)local_108 + lVar4);

      uVar9 = 0;

      uVar8 = 0;

      *param_5 = 0xffffffff;

      if (local_res8[0] != 0) {

        do {

          uVar3 = *param_1;

          *(undefined8 *)((longlong)auStack_130 + lVar4) = 0x1401bb4de;

          cVar5 = FUN_140174060(uVar3,param_3,uVar8);

          if ((cVar5 != '\0') &&

             (uVar1 = *(uint *)((longlong)local_108 + lVar4 + (ulonglong)uVar8 * 0x18),

             (uVar1 & 1) != 0)) {

            uVar7 = 1;

            if ((uVar1 & 2) != 0) {

              uVar7 = (uVar1 & 4 | 8) >> 2;

            }

            if (uVar9 < uVar7) {

              *param_5 = uVar8;

              uVar9 = uVar7;

            }

          }

          uVar8 = uVar8 + 1;

        } while (uVar8 < local_res8[0]);

        return *param_5 != 0xffffffff;

      }

    }

  }

  return false;

}




