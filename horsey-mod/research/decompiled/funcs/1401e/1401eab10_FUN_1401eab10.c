// Address: 0x1401eab10
// Ghidra name: FUN_1401eab10
// ============ 0x1401eab10 FUN_1401eab10 (size=434) ============


ulonglong FUN_1401eab10(longlong param_1,longlong param_2,int *param_3,undefined8 param_4,

                       undefined4 param_5,undefined8 param_6,undefined4 param_7,undefined8 param_8,

                       undefined4 param_9)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  ulonglong uVar4;

  

  lVar1 = *(longlong *)(param_2 + 0x138);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  if (lVar1 == 0) {

    uVar4 = FUN_14012e850("Texture is not currently available");

    return uVar4;

  }

  uVar4 = FUN_1401ea670(lVar2,*(undefined8 *)(lVar1 + 8),0,*param_3,param_3[1],param_3[2],param_3[3]

                        ,param_4,param_5,lVar1 + 0x18);

  if ((char)uVar4 != '\0') {

    uVar4 = FUN_1401ea670(lVar2,*(undefined8 *)(lVar1 + 0x58),0,*param_3 / 2,param_3[1] / 2,

                          (param_3[2] + 1) / 2,(param_3[3] + 1) / 2,param_6,param_7,lVar1 + 0x68);

    if ((char)uVar4 != '\0') {

      uVar4 = FUN_1401ea670(lVar2,*(undefined8 *)(lVar1 + 0x78),0,*param_3 / 2,param_3[1] / 2,

                            (param_3[2] + 1) / 2,(param_3[3] + 1) / 2,param_8,param_9,lVar1 + 0x88);

      if ((char)uVar4 != '\0') {

        lVar3 = *(longlong *)(lVar2 + 0x422c8);

        if (*(longlong *)(lVar1 + 0x10) == lVar3) {

          *(undefined8 *)(lVar2 + 0x422c8) = 0;

        }

        return CONCAT71((int7)((ulonglong)lVar3 >> 8),1);

      }

    }

  }

  return uVar4 & 0xffffffffffffff00;

}




