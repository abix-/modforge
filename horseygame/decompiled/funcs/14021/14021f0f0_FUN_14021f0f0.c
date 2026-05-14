// Address: 0x14021f0f0
// Ghidra name: FUN_14021f0f0
// ============ 0x14021f0f0 FUN_14021f0f0 (size=401) ============


ulonglong FUN_14021f0f0(longlong *param_1,short param_2,undefined4 param_3,undefined4 param_4,

                       undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8,

                       undefined4 param_9,longlong param_10)



{

  short *psVar1;

  longlong lVar2;

  ulonglong uVar3;

  short local_res10 [4];

  undefined2 local_res18 [4];

  undefined2 local_res20 [4];

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined2 local_1c;

  undefined2 local_1a;

  undefined2 local_18;

  undefined2 local_16;

  undefined4 local_14;

  

  local_res18[0] = 0xffff;

  local_res20[0] = 0;

  local_28 = 0;

  local_1c = param_5;

  local_1a = param_6;

  local_18 = param_7;

  local_16 = param_8;

  local_14 = param_9;

  local_res10[0] = param_2;

  local_24 = param_4;

  local_20 = param_3;

  FUN_14021fa90(&local_1c,&local_1a);

  FUN_14021fa90(&local_18,&local_16);

  uVar3 = FUN_14021f460(param_1,4);

  if ((char)uVar3 != '\0') {

    uVar3 = FUN_14021f290(param_1,&local_28,0x18);

    if ((char)uVar3 != '\0') {

      uVar3 = FUN_14021f290(param_1,local_res18,2);

      if ((char)uVar3 != '\0') {

        uVar3 = FUN_14021f290(param_1,local_res10,2);

        if ((char)uVar3 != '\0') {

          if ((local_res10[0] == 0x80) || ((local_res10[0] == 0x82 && (param_10 != 0)))) {

            uVar3 = FUN_14021f3b0(param_1);

          }

          else {

            uVar3 = FUN_14021f290(param_1,local_res18,2);

            if ((char)uVar3 == '\0') goto LAB_14021f274;

            uVar3 = FUN_14021f290(param_1,&stack0x00000058,2);

          }

          if ((char)uVar3 != '\0') {

            uVar3 = FUN_14021f290(param_1,local_res20,2);

            if ((char)uVar3 != '\0') {

              if (local_res10[0] == 0x80) {

                *(short *)(param_1 + 4) = (short)param_1[4] + 1;

              }

              lVar2 = *param_1;

              psVar1 = (short *)(lVar2 + 0x10);

              *psVar1 = *psVar1 + 1;

              return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);

            }

          }

        }

      }

    }

  }

LAB_14021f274:

  return uVar3 & 0xffffffffffffff00;

}




