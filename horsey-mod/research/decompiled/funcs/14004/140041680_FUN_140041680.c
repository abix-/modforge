// Address: 0x140041680
// Ghidra name: FUN_140041680
// ============ 0x140041680 FUN_140041680 (size=626) ============


undefined4 * FUN_140041680(char *param_1,int *param_2,undefined4 *param_3,longlong *param_4)



{

  errno_t eVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined4 *puVar5;

  longlong lVar6;

  longlong lVar7;

  undefined4 *puVar8;

  uint uVar9;

  FILE *local_7a8 [2];

  undefined1 local_798 [8];

  int local_790;

  FILE *local_768;

  undefined4 local_760;

  undefined4 local_75c;

  int local_740;

  longlong local_718;

  int local_708;

  int local_704;

  undefined4 local_88;

  undefined4 *puVar10;

  

  eVar1 = fopen_s(local_7a8,param_1,"rb");

  if (eVar1 != 0) {

    return (undefined4 *)0xffffffff;

  }

  if (local_7a8[0] == (FILE *)0x0) {

    return (undefined4 *)0xffffffff;

  }

  iVar2 = FUN_1402cf00c(local_7a8[0]);

  FUN_1402cea4c(local_7a8[0],0,2);

  iVar3 = FUN_1402cf00c(local_7a8[0]);

  FUN_1402cea4c(local_7a8[0],iVar2,0);

  FUN_1402f94c0(local_798,0,0x770);

  local_88 = 0xffffffff;

  local_768 = local_7a8[0];

  local_760 = FUN_1402cf00c(local_7a8[0]);

  local_75c = 1;

  local_740 = iVar3 - iVar2;

  iVar2 = FUN_140050ad0(local_798);

  puVar8 = (undefined4 *)0x0;

  if (iVar2 != 0) {

    local_790 = local_790 + 0x770;

    if (local_718 == 0) {

      puVar5 = (undefined4 *)_malloc_base(0x770);

      iVar2 = local_708;

    }

    else {

      puVar5 = (undefined4 *)(local_718 + local_708);

      iVar2 = local_708 + 0x770;

      if (local_704 < local_708 + 0x770) goto LAB_1400417af;

    }

    local_708 = iVar2;

    if (puVar5 != (undefined4 *)0x0) {

      FUN_1402f8e20(puVar5,local_798,0x770);

      FUN_140055360(puVar5);

      goto LAB_1400417bc;

    }

  }

LAB_1400417af:

  FUN_140054630(local_798);

  puVar5 = puVar8;

LAB_1400417bc:

  if (puVar5 == (undefined4 *)0x0) {

    return (undefined4 *)0xffffffff;

  }

  iVar2 = puVar5[1] * 0x1000;

  *param_2 = puVar5[1];

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = *puVar5;

  }

  lVar6 = _malloc_base((longlong)iVar2 * 2);

  if (lVar6 != 0) {

    iVar4 = FUN_140042de0(puVar5,puVar5[1],lVar6,iVar2);

    iVar3 = iVar2;

    puVar10 = puVar8;

    do {

      if (iVar4 == 0) {

        *param_4 = lVar6;

        FUN_140054630(puVar5);

        if (*(longlong *)(puVar5 + 0x20) == 0) {

          thunk_FUN_1402e9a80(puVar5);

          return puVar8;

        }

        return puVar8;

      }

      puVar8 = (undefined4 *)(ulonglong)(uint)((int)puVar8 + iVar4);

      uVar9 = (int)puVar10 + iVar4 * puVar5[1];

      puVar10 = (undefined4 *)(ulonglong)uVar9;

      lVar7 = lVar6;

      if (iVar3 < (int)(uVar9 + iVar2)) {

        iVar3 = iVar3 * 2;

        lVar7 = _realloc_base(lVar6,(longlong)iVar3 * 2);

        if (lVar7 == 0) {

          thunk_FUN_1402e9a80(lVar6);

          FUN_140054630(puVar5);

          lVar6 = *(longlong *)(puVar5 + 0x20);

          goto LAB_1400418da;

        }

      }

      iVar4 = FUN_140042de0(puVar5,puVar5[1],lVar7 + (longlong)(int)uVar9 * 2,iVar3 - uVar9);

      lVar6 = lVar7;

    } while( true );

  }

  FUN_140054630();

  lVar6 = *(longlong *)(puVar5 + 0x20);

LAB_1400418da:

  if (lVar6 == 0) {

    thunk_FUN_1402e9a80(puVar5);

  }

  return (undefined4 *)0xfffffffe;

}




