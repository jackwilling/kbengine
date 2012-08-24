/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __KBE_ENTITY_TABLE__
#define __KBE_ENTITY_TABLE__

#include "cstdkbe/cstdkbe.hpp"
#include "cstdkbe/singleton.hpp"
#include "helper/debug_helper.hpp"

namespace KBEngine { 

class DBUtil;
class DBInterface;
class ScriptDefModule;

/*
	ά��entity�����ݿ��еı�
*/
class EntityTable
{
public:
	EntityTable(){};
	virtual ~EntityTable(){};
	
	/**
		��ʼ��
	*/
	virtual bool initialize(ScriptDefModule* sm) = 0;
	/**
		ͬ��entity�������ݿ���
	*/
	virtual bool syncToDB() = 0;
protected:
};

class EntityTables : public Singleton<EntityTables>
{
public:
	EntityTables();
	virtual ~EntityTables();
	
	bool load(DBInterface* dbi);

	bool syncAllToDB();
protected:
};

}

#endif // __KBE_ENTITY_TABLE__