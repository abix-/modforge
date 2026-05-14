// Address: 0x1401ea9f0
// Ghidra name: FUN_1401ea9f0
// ============ 0x1401ea9f0 FUN_1401ea9f0 (size=276) ============


ulonglong FUN_1401ea9f0(longlong param_1,longlong param_2,undefined4 *param_3,undefined8 param_4,

                       undefined4 param_5,undefined8 param_6,undefined4 param_7)



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

  if (((char)uVar4 != '\0') &&

     (uVar4 = FUN_1401ea670(lVar2,*(undefined8 *)(lVar1 + 8),1,*param_3,param_3[1],

                            param_3[2] + 1 & 0xfffffffe,param_3[3] + 1 & 0xfffffffe,param_6,param_7,

                            lVar1 + 0x18), (char)uVar4 != '\0')) {

    lVar3 = *(longlong *)(lVar2 + 0x422c8);

    if (*(longlong *)(lVar1 + 0x10) == lVar3) {

      *(undefined8 *)(lVar2 + 0x422c8) = 0;

    }

    return CONCAT71((int7)((ulonglong)lVar3 >> 8),1);

  }

  return uVar4 & 0xffffffffffffff00;

}




