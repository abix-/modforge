// Address: 0x140024a60
// Ghidra name: FUN_140024a60
// ============ 0x140024a60 FUN_140024a60 (size=84) ============


void FUN_140024a60(undefined8 *param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  

  *param_1 = TiXmlNode::vftable;

  puVar2 = (undefined8 *)param_1[5];

  while (puVar2 != (undefined8 *)0x0) {

    puVar1 = (undefined8 *)puVar2[0xc];

    (**(code **)*puVar2)(puVar2,1);

    puVar2 = puVar1;

  }

  FUN_140027900(param_1 + 7);

  *param_1 = TiXmlBase::vftable;

  return;

}




