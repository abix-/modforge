// Address: 0x140088350
// Ghidra name: FUN_140088350
// ============ 0x140088350 FUN_140088350 (size=735) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140088350(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  byte bVar3;

  int *piVar4;

  int iVar5;

  longlong *plVar6;

  int iVar7;

  ulonglong uVar8;

  char local_28 [8];

  ulonglong uStack_20;

  undefined8 local_18;

  undefined8 local_10;

  

  FUN_1400d0a00(param_1,0);

  iVar7 = 0;

  if (*(char *)(*(longlong *)(DAT_1403fb0d8 + 0x300) + 0xac) == '\0') {

    FUN_1400cd5a0(param_1,CONCAT71((int7)((ulonglong)*(longlong *)(DAT_1403fb0d8 + 0x300) >> 8),1));

  }

  else {

    *(undefined1 *)(param_1 + 0x234) = 1;

    DAT_1403f3550 = 0;

    *(undefined8 *)(param_1 + 0x23c) = 0;

    *(undefined4 *)(param_1 + 0x238) = 0;

    FUN_1400cf540(param_1,0,*(float *)(param_1 + 0x118) - *(float *)(DAT_1403f4e00 + 0x254),

                  *(float *)(param_1 + 0x11c) - *(float *)(DAT_1403f4e00 + 600),

                  *(float *)(DAT_1403f4e00 + 0x254),*(float *)(DAT_1403f4e00 + 600));

  }

  FUN_1400ce540(param_1,0,0);

  bVar3 = FUN_14010dd70(DAT_1403fb0d8);

  *(uint *)(param_1 + 0x250) = (uint)bVar3;

  if (DAT_1403d9540 == 0) {

    piVar4 = &DAT_1403d9570;

    if (0xf < DAT_1403d9588) {

      piVar4 = _DAT_1403d9570;

    }

    if (DAT_1403d9580 != 6) goto LAB_140088455;

    iVar5 = *piVar4 + -0x73697243;

    if (iVar5 == 0) {

      iVar5 = *(ushort *)(piVar4 + 1) - 0x7270;

    }

    if (iVar5 != 0) goto LAB_140088455;

  }

  *(undefined4 *)(param_1 + 0x250) = 2;

LAB_140088455:

  *(undefined4 *)(param_1 + 0x254) = 0;

  *(undefined8 *)(param_1 + 0x46c) = 0;

  *(undefined8 *)(param_1 + 0x478) = 1;

  *(undefined4 *)(param_1 + 0x474) = 1;

  *(undefined4 *)(param_1 + 0x488) = 0xffffffff;

  *(undefined4 *)(param_1 + 0x260) = 0;

  *(undefined4 *)(param_1 + 0x484) = 0;

  *(undefined8 *)(param_1 + 0x278) = 0;

  *(undefined1 *)(param_1 + 600) = DAT_1403d9599;

  *(undefined4 *)(param_1 + 0x48c) = 0;

  *(undefined1 *)(param_1 + 0x264) = 0;

  *(undefined8 *)(param_1 + 0x280) = 0;

  *(undefined4 *)(param_1 + 0x288) = 0;

  *(undefined8 *)(param_1 + 0x494) = 0;

  if (*(longlong *)(param_1 + 0x270) == 0) {

    plVar6 = *(longlong **)(param_1 + 0xb8);

    uVar8 = *(longlong *)(param_1 + 0xc0) - (longlong)plVar6 >> 3;

    if (uVar8 != 0) {

      do {

        lVar1 = *plVar6;

        if (*(int *)(lVar1 + 8) == 3) {

          lVar2 = *(longlong *)(param_1 + 0x78);

          if ((*(float *)(lVar2 + 0x30) <= *(float *)(lVar1 + 0x28)) &&

             (*(float *)(lVar1 + 0x28) < *(float *)(lVar2 + 0x30) + *(float *)(lVar2 + 0x38))) {

            if ((*(float *)(lVar2 + 0x34) <= *(float *)(lVar1 + 0x2c)) &&

               (*(float *)(lVar1 + 0x2c) < *(float *)(lVar2 + 0x34) + *(float *)(lVar2 + 0x3c))) {

              *(longlong *)(param_1 + 0x270) = lVar1;

              *(undefined4 *)(lVar1 + 0x28) = *(undefined4 *)(param_1 + 0x268);

              *(undefined4 *)(*(longlong *)(param_1 + 0x270) + 0x2c) =

                   *(undefined4 *)(param_1 + 0x26c);

              break;

            }

          }

        }

        iVar7 = iVar7 + 1;

        plVar6 = plVar6 + 1;

      } while ((ulonglong)(longlong)iVar7 < uVar8);

    }

  }

  lVar1 = *(longlong *)(param_1 + 0x270);

  if (*(char *)(*(longlong *)(DAT_1403fb0d8 + 0x300) + 0xac) == '\0') {

    if (lVar1 != 0) {

      *(undefined4 *)(lVar1 + 0x28) = *(undefined4 *)(param_1 + 0x268);

      *(undefined4 *)(*(longlong *)(param_1 + 0x270) + 0x2c) = *(undefined4 *)(param_1 + 0x26c);

    }

    return 1;

  }

  if (lVar1 != 0) {

    *(undefined4 *)(param_1 + 0x280) = 1;

    *(undefined4 *)(param_1 + 0x284) = 0x78;

    *(undefined8 *)(param_1 + 0x250) = 0xc;

    local_28[0] = s_VialWorld_14030b138[0];

    local_28[1] = s_VialWorld_14030b138[1];

    local_28[2] = s_VialWorld_14030b138[2];

    local_28[3] = s_VialWorld_14030b138[3];

    local_28[4] = s_VialWorld_14030b138[4];

    local_28[5] = s_VialWorld_14030b138[5];

    local_28[6] = s_VialWorld_14030b138[6];

    local_28[7] = s_VialWorld_14030b138[7];

    local_18 = 9;

    local_10 = 0xf;

    uStack_20 = (ulonglong)(byte)s_VialWorld_14030b138[8];

    FUN_14003f340(local_28,CONCAT71((int7)((ulonglong)lVar1 >> 8),1));

    return 1;

  }

  return 0;

}




