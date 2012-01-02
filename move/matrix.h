#ifndef __MATRIX_H
#define __MATRIX_H

#include <stdexcept>
#include <sstream>
#include <vector>

template<typename ValueType>
class matrix
{
public:
    matrix(matrix<ValueType>&& other) : rows_(other.rows_), columns_(other.columns_), data_(std::move(other.data_))
    {
    }
	
	matrix(const matrix<ValueType>& other) : rows_(other.rows_), columns_(other.columns_), data_(other.data_)
	{
	}

    matrix(size_t rows, size_t columns) : rows_(rows), columns_(columns), data_()
    {
        for (size_t i = 0; i < rows_; ++i)
        {
            data_.push_back(std::vector<ValueType>(columns_));
        }
    }

    size_t rows() const
    {
        return rows_;
    }

    size_t columns() const
    {
        return columns_;
    }

    ValueType operator()(size_t row, size_t column) const
    {
        validate_row(row);
        validate_column(column);

        return data_[row-1][column-1];
    }

    ValueType& operator()(size_t row, size_t column)
    {
        validate_row(row);
        validate_column(column);

        return data_[row-1][column-1];
    }

private:
    size_t rows_;
    size_t columns_;
    std::vector<std::vector<ValueType>> data_;

    matrix() : rows_(0), columns_(0), data_()
    {
    }

    void validate_row(size_t row) const
    {
        if (row == 0 || row > rows_)
        {
            std::stringstream message;
            message << "Invalid index - actual number of rows: " << rows_ << " requested index:  "
                    << row << std::endl;
            throw std::invalid_argument(message.str());
        }
    }

    void validate_column(size_t column) const
    {
        if (column == 0 || column > columns_)
        {
            std::stringstream message;
            message << "Invalid index - actual number of columns: " << columns_ << " requested index:  "
                    << column << std::endl;
            throw std::invalid_argument(message.str());
        }
    }
};

#endif // __MATRIX_H
