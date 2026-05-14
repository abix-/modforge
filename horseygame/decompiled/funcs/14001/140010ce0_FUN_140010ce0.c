// Address: 0x140010ce0
// Ghidra name: FUN_140010ce0
// ============ 0x140010ce0 FUN_140010ce0 (size=653) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_140010ce0(undefined8 *param_1,longlong *param_2)



{

  undefined4 uVar1;

  longlong lVar2;

  longlong lVar3;

  undefined8 uVar4;

  longlong lVar5;

  bool bVar6;

  bool bVar7;

  float fVar8;

  ulonglong uVar9;

  uint uVar10;

  ulonglong uVar11;

  undefined4 *puVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  undefined1 auStack_148 [32];

  char local_128;

  uint local_124;

  undefined1 local_120 [16];

  float local_110;

  undefined1 local_108 [4];

  undefined2 local_104;

  undefined8 local_f8;

  undefined8 uStack_f0;

  undefined8 local_e8;

  undefined8 uStack_e0;

  undefined4 local_d8;

  undefined4 uStack_d4;

  undefined4 uStack_d0;

  undefined4 uStack_cc;

  undefined4 local_c8;

  undefined4 uStack_c4;

  undefined4 uStack_c0;

  int iStack_bc;

  undefined1 local_b8 [16];

  undefined8 local_a8;

  undefined8 local_a0;

  undefined1 local_98 [16];

  undefined8 local_88;

  undefined8 local_80;

  undefined4 local_78;

  undefined4 uStack_74;

  undefined4 uStack_70;

  undefined4 uStack_6c;

  undefined4 local_68;

  undefined4 uStack_64;

  undefined4 uStack_60;

  undefined4 uStack_5c;

  undefined1 local_58;

  ulonglong local_48;

  

  local_48 = DAT_1403e8b00 ^ (ulonglong)auStack_148;

  *(uint *)(param_1 + 1) = *(uint *)(param_1 + 1) | 4;

  local_f8 = param_1[0xf];

  uStack_f0 = param_1[0x10];

  local_e8 = param_1[0x11];

  uStack_e0 = param_1[0x12];

  lVar2 = param_1[0xc];

  local_124 = *(uint *)(param_1 + 1) & 2;

  local_128 = local_124 != 0;

  local_d8 = *(undefined4 *)(param_1 + 0x13);

  uStack_d4 = *(undefined4 *)((longlong)param_1 + 0x9c);

  uStack_d0 = *(undefined4 *)(param_1 + 0x14);

  uStack_cc = *(undefined4 *)((longlong)param_1 + 0xa4);

  local_c8 = *(undefined4 *)(param_1 + 0x15);

  uStack_c4 = *(undefined4 *)((longlong)param_1 + 0xac);

  uStack_c0 = *(undefined4 *)(param_1 + 0x16);

  iStack_bc = *(int *)((longlong)param_1 + 0xb4);

  if ((*(char *)(lVar2 + 0x3a) == '\0') && (*(char *)(param_1[0xd] + 0x3a) == '\0')) {

    lVar2 = *(longlong *)(lVar2 + 0x10);

    bVar7 = false;

    lVar3 = *(longlong *)(param_1[0xd] + 0x10);

    (**(code **)*param_1)(local_d8,param_1 + 0xf,lVar2 + 0xc,lVar3 + 0xc);

    bVar6 = 0 < *(int *)((longlong)param_1 + 0xb4);

    uVar14 = 0;

    if (0 < *(int *)((longlong)param_1 + 0xb4)) {

      puVar12 = (undefined4 *)((longlong)param_1 + 0x84);

      uVar13 = uVar14;

      do {

        *(undefined8 *)(puVar12 + -1) = 0;

        uVar9 = uVar14;

        uVar11 = uVar14;

        if (0 < iStack_bc) {

          do {

            if (*(int *)((longlong)&local_e8 + uVar9) == puVar12[1]) {

              puVar12[-1] = *(undefined4 *)((longlong)&uStack_f0 + uVar9);

              *puVar12 = *(undefined4 *)((longlong)&uStack_f0 + uVar9 + 4);

              break;

            }

            uVar10 = (int)uVar11 + 1;

            uVar9 = uVar9 + 0x14;

            uVar11 = (ulonglong)uVar10;

          } while ((int)uVar10 < iStack_bc);

        }

        uVar10 = (int)uVar13 + 1;

        uVar13 = (ulonglong)uVar10;

        puVar12 = puVar12 + 5;

      } while ((int)uVar10 < *(int *)((longlong)param_1 + 0xb4));

    }

    if (bVar6 != (bool)local_128) {

      if ((*(ushort *)(lVar2 + 4) & 2) == 0) {

        *(undefined4 *)(lVar2 + 0xac) = 0;

        *(ushort *)(lVar2 + 4) = *(ushort *)(lVar2 + 4) | 2;

      }

      if ((*(ushort *)(lVar3 + 4) & 2) == 0) {

        *(undefined4 *)(lVar3 + 0xac) = 0;

        *(ushort *)(lVar3 + 4) = *(ushort *)(lVar3 + 4) | 2;

      }

    }

  }

  else {

    uVar1 = *(undefined4 *)((longlong)param_1 + 0x74);

    lVar3 = *(longlong *)(param_1[0xd] + 0x10);

    uVar4 = *(undefined8 *)(param_1[0xd] + 0x18);

    lVar5 = *(longlong *)(lVar2 + 0x10);

    local_a8 = 0;

    local_a0 = 0;

    local_88 = 0;

    local_80 = 0;

    FUN_140016340(local_b8,*(undefined8 *)(lVar2 + 0x18),*(undefined4 *)(param_1 + 0xe));

    FUN_140016340(local_98,uVar4,uVar1);

    local_78 = *(undefined4 *)(lVar5 + 0xc);

    uStack_74 = *(undefined4 *)(lVar5 + 0x10);

    uStack_70 = *(undefined4 *)(lVar5 + 0x14);

    uStack_6c = *(undefined4 *)(lVar5 + 0x18);

    local_58 = 1;

    local_68 = *(undefined4 *)(lVar3 + 0xc);

    uStack_64 = *(undefined4 *)(lVar3 + 0x10);

    uStack_60 = *(undefined4 *)(lVar3 + 0x14);

    uStack_5c = *(undefined4 *)(lVar3 + 0x18);

    local_104 = 0;

    FUN_140016c70(local_120,local_108,local_b8);

    fVar8 = DAT_14039c9f4;

    bVar7 = true;

    *(undefined4 *)((longlong)param_1 + 0xb4) = 0;

    bVar6 = local_110 < fVar8;

  }

  uVar10 = *(uint *)(param_1 + 1) | 2;

  if (!bVar6) {

    uVar10 = *(uint *)(param_1 + 1) & 0xfffffffd;

  }

  *(uint *)(param_1 + 1) = uVar10;

  if (local_124 == 0) {

    if ((bVar6) && (param_2 != (longlong *)0x0)) {

      (**(code **)(*param_2 + 8))(param_2,param_1);

    }

  }

  else if ((!bVar6) && (param_2 != (longlong *)0x0)) {

    (**(code **)(*param_2 + 0x10))(param_2,param_1);

  }

  if (((!bVar7) && (bVar6)) && (param_2 != (longlong *)0x0)) {

    (**(code **)(*param_2 + 0x18))(param_2,param_1,&local_f8);

  }

  return;

}




