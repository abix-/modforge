// Address: 0x140101300
// Ghidra name: FUN_140101300
// ============ 0x140101300 FUN_140101300 (size=617) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140101300(longlong param_1,float param_2,float param_3,char param_4)



{

  int iVar1;

  longlong lVar2;

  float fVar3;

  undefined4 uVar4;

  float fVar5;

  float fVar6;

  ulonglong in_stack_fffffffffffffef8;

  undefined4 local_d8;

  undefined4 local_d4;

  float local_d0;

  float local_cc;

  longlong local_c8;

  ulonglong uStack_c0;

  undefined8 local_b8;

  ulonglong uStack_b0;

  

  lVar2 = 10;

  do {

    fVar3 = (float)FUN_1400c6940();

    if (param_4 == '\0') {

      fVar5 = 0.0;

      fVar6 = fVar3;

    }

    else {

      fVar6 = 0.0;

      fVar5 = fVar3;

    }

    uVar4 = FUN_1400c6940();

    local_d8 = FUN_1400c6940();

    local_d0 = fVar5 + param_2;

    local_cc = fVar6 + param_3;

    local_d4 = uVar4;

    iVar1 = FUN_1400c6580(2);

    uVar4 = 1;

    in_stack_fffffffffffffef8 = in_stack_fffffffffffffef8 & 0xffffffff00000000;

    FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),0xffffffff,&local_d0,&local_d8,

                  in_stack_fffffffffffffef8,0,&DAT_1403dc2bc,0x2d,(float)(iVar1 + 2));

    lVar2 = lVar2 + -1;

  } while (lVar2 != 0);

  local_b8 = _DAT_1403033f0;

  uStack_b0 = _UNK_1403033f8;

  local_c8._0_1_ = s_SmashFence_140313750[0];

  local_c8._1_1_ = s_SmashFence_140313750[1];

  local_c8._2_1_ = s_SmashFence_140313750[2];

  local_c8._3_1_ = s_SmashFence_140313750[3];

  local_c8._4_1_ = s_SmashFence_140313750[4];

  local_c8._5_1_ = s_SmashFence_140313750[5];

  local_c8._6_1_ = s_SmashFence_140313750[6];

  local_c8._7_1_ = s_SmashFence_140313750[7];

  uStack_c0 = (ulonglong)(ushort)s_SmashFence_140313750._8_2_;

  FUN_14010de70(param_1,&local_c8,0xffffffff,CONCAT44(param_3,param_2),0x14,100,

                CONCAT44(uVar4,DAT_14039ca44));

  if (0xf < uStack_b0) {

    if (0xfff < uStack_b0 + 1) {

      if (0x1f < (local_c8 - *(longlong *)(local_c8 + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  return;

}




