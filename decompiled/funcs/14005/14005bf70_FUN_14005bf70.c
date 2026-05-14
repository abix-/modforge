// Address: 0x14005bf70
// Ghidra name: FUN_14005bf70
// ============ 0x14005bf70 FUN_14005bf70 (size=988) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14005bf70(longlong param_1)



{

  float fVar1;

  int iVar2;

  longlong lVar3;

  undefined8 uVar4;

  undefined8 local_248;

  undefined8 uStack_240;

  undefined8 local_238;

  ulonglong uStack_230;

  undefined8 local_228;

  undefined8 uStack_220;

  undefined4 local_218;

  undefined4 local_214;

  int *local_210 [2];

  longlong local_200;

  undefined1 local_1f8 [496];

  

  FUN_1400d01d0(param_1,"Eddy Bentfoot");

  iVar2 = FUN_14005e250(0x1f);

  *(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0xcc + (longlong)iVar2 * 4) = 0x1f;

  iVar2 = FUN_14005e250(0x21);

  *(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0xcc + (longlong)iVar2 * 4) = 0x21;

  FUN_1400b3070(*(undefined8 *)(param_1 + 0x148));

  FUN_1400cc9d0(param_1,4,DAT_1403065b4,DAT_1403065c8);

  FUN_1400cc9d0(param_1,4,DAT_1403065b8,DAT_1403065cc);

  FUN_1400cc9d0(param_1,4,DAT_1403065bc,DAT_1403065d0);

  local_228 = _DAT_1403065e0;

  uStack_220 = _UNK_1403065e8;

  local_218 = 0x43050000;

  local_214 = 0x431a0000;

  FUN_1400c5d10(local_210,3);

  uStack_240 = 0;

  local_238 = _DAT_140304080;

  uStack_230 = _UNK_140304088;

  local_248._0_5_ = CONCAT14(s_human_140303b0c[4],s_human_140303b0c._0_4_);

  local_248 = (ulonglong)(uint5)local_248;

  FUN_1400a2ed0(local_1f8,&local_248);

  if (0xf < uStack_230) {

    if (0xfff < uStack_230 + 1) {

      if (0x1f < (local_248 - *(longlong *)(local_248 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  fVar1 = DAT_140303354;

  lVar3 = FUN_1400cc9d0(param_1,6,*(float *)(&local_228 + *local_210[0]) * DAT_140303354,

                        *(float *)((longlong)&local_228 + (longlong)*local_210[0] * 8 + 4) *

                        DAT_140303354);

  FUN_14005d190(lVar3,local_1f8);

  *(undefined4 *)(lVar3 + 0x70) = 1;

  uStack_240 = 0;

  local_238 = _DAT_140304080;

  uStack_230 = _UNK_140304088;

  local_248._0_5_ = CONCAT14(s_tiger_140306550[4],s_tiger_140306550._0_4_);

  local_248 = (ulonglong)(uint5)local_248;

  FUN_1400a2ed0(local_1f8,&local_248);

  if (0xf < uStack_230) {

    if (0xfff < uStack_230 + 1) {

      if (0x1f < (local_248 - *(longlong *)(local_248 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  uVar4 = FUN_1400cc9d0(param_1,6,*(float *)(&local_228 + local_210[0][1]) * fVar1,

                        *(float *)((longlong)&local_228 + (longlong)local_210[0][1] * 8 + 4) * fVar1

                       );

  FUN_14005d190(uVar4,local_1f8);

  uStack_240 = 0;

  local_238 = _DAT_140305680;

  uStack_230 = _UNK_140305688;

  local_248 = 0x72616562;

  FUN_1400a2ed0(local_1f8,&local_248);

  if (0xf < uStack_230) {

    if (0xfff < uStack_230 + 1) {

      if (0x1f < (local_248 - *(longlong *)(local_248 + -8)) - 8) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  uVar4 = FUN_1400cc9d0(param_1,6,*(float *)(&local_228 + local_210[0][2]) * fVar1,

                        *(float *)((longlong)&local_228 + (longlong)local_210[0][2] * 8 + 4) * fVar1

                       );

  FUN_14005d190(uVar4,local_1f8);

  *(undefined1 *)(param_1 + 0x254) = 0;

  if (local_210[0] != (int *)0x0) {

    if (0xfff < (local_200 - (longlong)local_210[0] & 0xfffffffffffffffcU)) {

      if (0x1f < (ulonglong)((longlong)local_210[0] + (-8 - *(longlong *)(local_210[0] + -2)))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  return;

}




