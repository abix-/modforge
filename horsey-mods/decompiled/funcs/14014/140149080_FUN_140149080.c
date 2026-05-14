// Address: 0x140149080
// Ghidra name: FUN_140149080
// ============ 0x140149080 FUN_140149080 (size=378) ============


undefined4 FUN_140149080(longlong param_1,longlong param_2,longlong param_3,undefined8 param_4)



{

  char cVar1;

  undefined4 uVar2;

  undefined4 *puVar3;

  longlong lVar4;

  undefined4 *puVar5;

  

  if ((param_2 == 0) && (param_3 == 0)) {

    FUN_14012e850("Parameter \'%s\' is invalid","callback");

    return 0;

  }

  cVar1 = thunk_FUN_140149460();

  if (cVar1 != '\0') {

    FUN_14018b130(&DAT_1403fc000);

    puVar3 = DAT_1403fc018;

    if (DAT_1403fc018 == (undefined4 *)0x0) {

      FUN_14018b190(&DAT_1403fc000);

      puVar3 = (undefined4 *)FUN_1401841f0(0x40);

      if (puVar3 == (undefined4 *)0x0) {

        return 0;

      }

    }

    else {

      DAT_1403fc018 = *(undefined4 **)(DAT_1403fc018 + 0xe);

      FUN_14018b190(&DAT_1403fc000);

      FUN_140149690(*puVar3);

    }

    uVar2 = FUN_1401aa810();

    *puVar3 = uVar2;

    *(longlong *)(puVar3 + 2) = param_2;

    *(longlong *)(puVar3 + 4) = param_3;

    *(undefined8 *)(puVar3 + 6) = param_4;

    *(longlong *)(puVar3 + 8) = param_1;

    lVar4 = FUN_140149300();

    *(longlong *)(puVar3 + 10) = lVar4 + param_1;

    FUN_140139010(puVar3 + 0xc,0);

    puVar5 = (undefined4 *)FUN_1401841f0(0x18);

    if (puVar5 != (undefined4 *)0x0) {

      *(undefined4 **)(puVar5 + 2) = puVar3;

      *puVar5 = *puVar3;

      FUN_140179b40(DAT_1403fbf78);

      *(undefined4 **)(puVar5 + 4) = DAT_1403fbf70;

      DAT_1403fbf70 = puVar5;

      FUN_140179b60(DAT_1403fbf78);

      FUN_14018b130(&DAT_1403fc000);

      *(undefined4 **)(puVar3 + 0xe) = DAT_1403fc010;

      DAT_1403fc010 = puVar3;

      FUN_14018b190(&DAT_1403fc000);

      FUN_14017cea0(DAT_1403fc008);

      return *puVar5;

    }

    FUN_1401841e0(puVar3);

  }

  return 0;

}




