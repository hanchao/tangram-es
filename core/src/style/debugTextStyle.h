#pragma once

#include "fontStyle.h"
#include "tangram.h"
#include "typedMesh.h"

class DebugTextStyle : public FontStyle {

protected:

    struct PosTexID {
        float pos_x;
        float pos_y;
        float tex_u;
        float tex_v;
        float fsID;
    };

    virtual void addData(TileData& _data, MapTile& _tile, const MapProjection& _mapProjection) const override;

    typedef TypedMesh<PosTexID> Mesh;

public:

    DebugTextStyle(const std::string& _fontName, std::string _name, float _fontSize, bool _sdf = false, GLenum _drawMode = GL_TRIANGLES);

};
