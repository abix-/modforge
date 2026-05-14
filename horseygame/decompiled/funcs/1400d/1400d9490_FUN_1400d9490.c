// Address: 0x1400d9490
// Ghidra name: FUN_1400d9490
// ============ 0x1400d9490 FUN_1400d9490 (size=1103) ============


bool FUN_1400d9490(char *param_1)



{

  ulonglong uVar1;

  undefined8 *puVar2;

  size_t sVar3;

  undefined8 ****ppppuVar4;

  longlong lVar5;

  ulonglong uVar6;

  undefined4 local_res10 [2];

  undefined8 ***local_48;

  undefined8 uStack_40;

  ulonglong local_38;

  ulonglong uStack_30;

  

  puVar2 = (undefined8 *)FUN_1400c4df0();

  lVar5 = puVar2[2];

  sVar3 = strlen(param_1);

  if (0x7fffffffffffffffU - lVar5 < sVar3) {

                    /* WARNING: Subroutine does not return */

    FUN_140024130();

  }

  if (0xf < (ulonglong)puVar2[3]) {

    puVar2 = (undefined8 *)*puVar2;

  }

  uVar1 = sVar3 + lVar5;

  uVar6 = 0xf;

  ppppuVar4 = &local_48;

  local_48 = (undefined8 ****)0x0;

  uStack_40 = 0;

  local_38 = 0;

  uStack_30 = 0;

  if (0xf < uVar1) {

    uVar6 = uVar1 | 0xf;

    if (uVar6 < 0x8000000000000000) {

      if (uVar6 < 0x16) {

        uVar6 = 0x16;

      }

    }

    else {

      uVar6 = 0x7fffffffffffffff;

    }

    ppppuVar4 = (undefined8 ****)FUN_1400285e0(uVar6 + 1);

    local_48 = ppppuVar4;

  }

  local_38 = uVar1;

  uStack_30 = uVar6;

  FUN_1402f8e20(ppppuVar4,puVar2,lVar5);

  FUN_1402f8e20((longlong)ppppuVar4 + lVar5,param_1);

  *(undefined1 *)((longlong)ppppuVar4 + uVar1) = 0;

  ppppuVar4 = &local_48;

  if (0xf < uStack_30) {

    ppppuVar4 = (undefined8 ****)local_48;

  }

  lVar5 = FUN_1402ce0f8(ppppuVar4,&DAT_14030a390);

  if (lVar5 != 0) {

    local_res10[0] = 0x66;

    FUN_1402d185c(local_res10,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a20,1,4,lVar5);

    FUN_1402d185c(&DAT_1403da90c,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a24,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a28,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a2c,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a30,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a34,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a38,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a3c,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a40,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a44,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a48,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a4c,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a50,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a54,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a58,1,1,lVar5);

    FUN_1402d185c(&DAT_1403f3a5c,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a60,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a64,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a68,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a6c,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a70,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a74,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a78,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a7c,1,4,lVar5);

    FUN_1402d185c(&DAT_1403f3a80,1);

    FUN_1402ce288(lVar5);

  }

  if (0xf < uStack_30) {

    if (0xfff < uStack_30 + 1) {

      if (0x1f < (ulonglong)((longlong)local_48 + (-8 - (longlong)local_48[-1]))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  return lVar5 != 0;

}




