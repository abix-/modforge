// Address: 0x140149300
// Ghidra name: FUN_140149300
// ============ 0x140149300 FUN_140149300 (size=77) ============


longlong FUN_140149300(void)



{

  longlong lVar1;

  ulonglong uVar2;

  

  if (DAT_1403fc030 == 0) {

    FUN_1401493a0();

  }

  lVar1 = FUN_140184280();

  uVar2 = (ulonglong)DAT_1403fc03c;

  return ((ulonglong)DAT_1403fc038 * ((ulonglong)(lVar1 - DAT_1403fc030) % uVar2)) / uVar2 +

         (ulonglong)DAT_1403fc038 * ((ulonglong)(lVar1 - DAT_1403fc030) / uVar2);

}




