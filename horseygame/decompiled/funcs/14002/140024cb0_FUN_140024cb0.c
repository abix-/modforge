// Address: 0x140024cb0
// Ghidra name: FUN_140024cb0
// ============ 0x140024cb0 FUN_140024cb0 (size=116) ============


void FUN_140024cb0(undefined8 *param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  

  *param_1 = TiXmlDocument::vftable;

  FUN_140027900(param_1 + 0xe);

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




